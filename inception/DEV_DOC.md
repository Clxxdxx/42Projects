# 🛠️ DEVELOPER DOCUMENTATION

This document explains how the Inception project was implemented from a developer perspective.  
It describes the structure of the containers, configuration logic, and main technical decisions.


# 📌 Project Overview

The objective of this project is to create a multi-container Docker infrastructure running:

- **Nginx** (HTTPS web server)
- **WordPress** (PHP-FPM)
- **MariaDB** (database)

Each service runs in its own container and communicates through a Docker network.

The project is fully automated using:

- Dockerfiles
- docker-compose
- initialization scripts
- Makefile


# 🧩 Services Implementation

## 🗄️ MariaDB Container

**Purpose:**  
Provide the database used by WordPress.

**Files used:**

```
requirements/mariadb/Dockerfile
requirements/mariadb/tools/init_db.sh
requirements/mariadb/conf/50-server.conf
```

**What happens inside the container:**

1. MariaDB is installed
2. Configuration file is copied
3. Database initialization script runs
4. Database and user are created
5. Permissions are assigned

**Initialization script:**

```
init_db.sh
```

This script:

- Starts MariaDB
- Creates database
- Creates user
- Sets passwords using Docker Secrets

Secrets used:

```
db_root_password
db_password
```


## 🌐 WordPress Container

**Purpose:**  
Run WordPress using PHP-FPM.

**Files used:**

```
requirements/wordpress/Dockerfile
requirements/wordpress/tools/setup_wordpress.sh
requirements/wordpress/conf/www.conf
```

**What happens inside the container:**

1. PHP and required modules are installed
2. WordPress is downloaded
3. Configuration file is created
4. WordPress is connected to MariaDB
5. Admin user is created automatically

**Setup script:**

```
setup_wordpress.sh
```

This script:

- Downloads WordPress
- Creates wp-config.php
- Configures database connection
- Creates admin user
- Starts PHP-FPM


## 🔐 Nginx Container

**Purpose:**  
Serve the website using HTTPS.

**Files used:**

```
requirements/nginx/Dockerfile
requirements/nginx/tools/generate_ssl.sh
requirements/nginx/conf/nginx.conf
```

**What happens inside the container:**

1. Nginx is installed
2. SSL certificate is generated
3. Configuration file is copied
4. HTTPS server starts

**SSL script:**

```
generate_ssl.sh
```

This script generates:

- Self-signed SSL certificate
- Private key

Protocols supported:

```
TLSv1.2
TLSv1.3
```


# 🐳 Docker Compose Logic

Main file:

```
srcs/docker-compose.yml
```

This file defines:

- Containers
- Networks
- Volumes
- Secrets
- Dependencies

Container order:

```
mariadb → wordpress → nginx
```

Dependencies:

```
wordpress depends on mariadb
nginx depends on wordpress
```

This ensures proper startup order.


# 🌐 Docker Network

Network used:

```
inception-network
```

Type:

```
bridge
```

Why this network:

- Allows container communication
- Provides isolation
- Uses internal DNS names

Example:

```
wordpress connects to mariadb
using hostname: mariadb
```


# 💾 Volumes Configuration

Two persistent volumes are used:

```
mariadb_data
wordpress_data
```

Paths:

```
/home/clalopez/data/mariadb
/home/clalopez/data/wordpress
```

Why volumes are used:

- Prevent data loss
- Persist database files
- Persist WordPress content

Without volumes, data would be deleted when containers stop.


# 🔐 Secrets Implementation

Secrets are used to store sensitive data.

Files:

```
secrets/db_root_password.txt
secrets/db_password.txt
```

Why secrets are used:

- Avoid exposing passwords
- Improve security
- Prevent hardcoded credentials

Secrets are mounted into:

```
/run/secrets/
```

Inside containers.


# ⚙️ Makefile Workflow

Main automation tool:

```
Makefile
```

Commands available:

| Command | Action |
|--|-|
| `make` | Build and start containers |
| `make clean` | Stop containers |
| `make fclean` | Remove containers and volumes |
| `make re` | Rebuild everything |

Typical workflow:

```
make
→ build images
→ create containers
→ start services
```


# 📦 Environment Variables

Environment variables are stored in:

```
srcs/.env
```

Examples:

```
DOMAIN_NAME
MYSQL_DATABASE
MYSQL_USER
WP_ADMIN_USER
WP_ADMIN_PASSWORD
```

They are used to:

- Configure services
- Avoid hardcoding values
- Simplify configuration changes


# 🧠 Design Decisions

## Why separate containers?

Each service runs in its own container to:

- Improve modularity
- Increase security
- Allow easier debugging
- Follow microservice design



## Why PHP-FPM instead of Apache?

PHP-FPM was used because:

- Better performance
- Compatible with Nginx
- More common in modern setups


## Why self-signed SSL?

Required by subject.

Used because:

- No external certificate authority allowed
- Enables HTTPS encryption


## Why Docker instead of Virtual Machines?

Docker was chosen because:

- Faster startup
- Lower resource usage
- Easier deployment
- Better scalability


# 🧪 Testing and Debugging

Common commands used during development:

Check running containers:

```bash
docker ps
```

Check logs:

```bash
docker logs nginx
docker logs wordpress
docker logs mariadb
```

Rebuild containers:

```bash
make re
```

Remove everything:

```bash
make fclean
```


# 🚧 Known Limitations

- Uses self-signed SSL certificate
- No external database access
- Requires manual `.env` configuration
- Designed for local environment only


# 📌 Conclusion

This project demonstrates:

- Multi-container Docker infrastructure
- Secure service communication
- Persistent data management
- Automated service deployment

It simulates a small production-like environment using container-based architecture.

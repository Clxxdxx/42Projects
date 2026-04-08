*This project has been created as part of the 42 curriculum by clalopez.* 

# 📖 Project Description

The goal of this project is to build a complete infrastructure composed of multiple services running in isolated Docker containers. These services communicate through a Docker network and persist data using volumes.

This project includes:

| Service | Description |
|--------|-------------|
| **Nginx** | Web server with SSL (TLSv1.2/v1.3) |
| **WordPress** | PHP-based CMS |
| **MariaDB** | Database server |
| **Docker Network** | Communication between containers |
| **Docker Volumes** | Persistent storage |
| **Docker Secrets** | Secure password handling |


# 🎯 Project Goals

- Understand **containerization**
- Learn **Docker architecture**
- Configure **multi-container environments**
- Manage **persistent storage**
- Implement **secure credential handling**
- Configure **SSL/TLS encryption**
- Deploy **WordPress with MariaDB**


# 🏗️ Architecture Overview

                🌐 HTTPS (443)
                     │
                     ▼
                ┌──────────┐
                │  NGINX   │
                │ Reverse  │
                │  Proxy   │
                └────┬─────┘
                     │
                     ▼
                ┌──────────┐
                │ WordPress│
                │   PHP    │
                └────┬─────┘
                     │
                     ▼
                ┌──────────┐
                │ MariaDB  │
                │ Database │
                └──────────┘


# 🐳 Docker Services

| Container | Purpose | Depends On |
|-----------|----------|------------|
| **nginx** | HTTPS reverse proxy | wordpress |
| **wordpress** | PHP CMS | mariadb |
| **mariadb** | Database server | — |


# 📂 Project Structure

.
├── DEV_DOC.md
├── Makefile
├── README.md
├── secrets
│   ├── db_password.txt
│   └── db_root_password.txt
├── srcs
│   ├── docker-compose.yml
│   └── requirements
│       ├── mariadb
│       ├── nginx
│       └── wordpress
└── USER_DOC.md


# ⚙️ Instructions

## 1️⃣ Requirements

You must have:

- Docker
- Docker Compose
- Make

Install Docker:
sudo apt install docker docker-compose

## 2️⃣ Setup Environment Variables

Create `.env` file inside:

srcs/

Example:

env
DOMAIN_NAME=clalopez.42.fr

MYSQL_DATABASE=wordpress
MYSQL_USER=wp_user

WP_ADMIN_USER=admin
WP_ADMIN_PASSWORD=admin123
WP_ADMIN_EMAIL=admin@mail.com

WP_USER=user
WP_USER_PASSWORD=user123
WP_USER_EMAIL=user@mail.com


## 3️⃣ Launch Project

Run:

bash
make

This will:

- Build Docker images
- Create containers
- Setup database
- Configure WordPress
- Generate SSL certificates
- Launch Nginx HTTPS server


## 4️⃣ Access Website

Open browser:

https://clalopez.42.fr


## 🧠 Design Choices

This project was designed using container-based architecture to ensure modularity, security, and scalability.

# ⚖️ Technical Comparisons

## 🖥️ Virtual Machines vs Docker

| Feature | Virtual Machines | Docker |
|--------|-----------------|--------|
| Startup Speed | Slow | Fast |
| Resource Usage | Heavy | Lightweight |
| Isolation | Full OS | Process-level |
| Performance | Lower | Higher |
| Portability | Limited | Very High |

**Why Docker?**
Docker allows faster deployment, lower resource usage, and easier scaling compared to Virtual Machines.

## 🔐 Secrets vs Environment Variables

| Feature | Environment Variables | Docker Secrets |
|--------|----------------------|---------------|
| Security | Medium | High |
| Storage | Plain text | Secure file |
| Access Control | Limited | Controlled |
| Exposure Risk | Higher | Lower |

**Why Secrets?**

Passwords are stored securely using Docker Secrets instead of exposing them in environment variables.

Used files:
secrets/db_password.txt
secrets/db_root_password.txt

## 🌐 Docker Network vs Host Network

| Feature | Bridge Network | Host Network |
|--------|----------------|-------------|
| Isolation | Yes | No |
| Security | Higher | Lower |
| Flexibility | High | Limited |
| Container Communication | Internal DNS | Direct |

**Why Bridge Network?**

Containers communicate securely using an isolated internal Docker network.

Network name:
inception-network

## 💾 Docker Volumes vs Bind Mounts

| Feature | Docker Volume | Bind Mount |
|--------|----------------|-------------|
| Performance | High | Medium |
| Flexibility | Managed | Manual |
| Portability | High | Low |
| Control | Docker-managed | OS-managed |

**Why Bind Mounts?**

Bind mounts were used to persist data locally:

/home/clalopez/data/mariadb
/home/clalopez/data/wordpress

This allows:

- Persistent database storage
- Persistent WordPress files


# 🔐 Security Features

- SSL/TLS encryption
- Docker Secrets
- Secure database authentication


# 🌐 Nginx Configuration

Nginx acts as:

- Reverse proxy
- SSL termination server
- HTTPS provider

Supported:

- TLSv1.2
- TLSv1.3

Certificate generated using:

generate_ssl.sh

---

# 🧩 WordPress Setup

WordPress container:

- Connects to MariaDB
- Automatically creates admin user
- Initializes database tables
- Configures PHP-FPM

Setup script:
setup_wordpress.sh


# 🗄️ MariaDB Setup

MariaDB container:

- Initializes database
- Creates database user
- Sets root password
- Grants privileges

Script used:
init_db.sh


# 🛠️ Makefile Commands

| Command | Description |
|--------|-------------|
| `make` | Build and start containers |
| `make clean` | Stop containers |
| `make fclean` | Remove containers and volumes |
| `make re` | Full rebuild |


# 📊 Docker Volumes

| Volume | Purpose |
|--------|---------|
| mariadb_data | Database storage |
| wordpress_data | Website files |


# 🌍 Docker Network

inception-network

Used for secure communication between:

- nginx
- wordpress
- mariadb

# 📚 Resources

## Official Documentation

- https://docs.docker.com/
- https://nginx.org/en/docs/
- https://mariadb.org/documentation/
- https://wordpress.org/support/
- https://docs.docker.com/compose/


## Tutorials & Articles

- Docker Compose Guide
- Nginx Reverse Proxy Setup
- WordPress Docker Installation
- MariaDB Configuration


# 🤖 AI Usage

Artificial Intelligence tools were used during the development of this project.

| Task | AI Usage |
|------|----------|
| README structure | Generated initial template |
| Documentation formatting | Markdown styling assistance |
| Concept clarification | Docker architecture explanations |
| Debugging help | Error explanation support |

Tools used:

- ChatGPT
- GeminiAI
- Claude

AI was used as a learning support tool, not as a replacement for manual implementation.


# ✅ Features Implemented

✔ MariaDB container  
✔ WordPress container  
✔ Nginx HTTPS container  
✔ Docker Secrets  
✔ Docker Network  
✔ Persistent Volumes  
✔ SSL Certificate  
✔ Multi-container setup  


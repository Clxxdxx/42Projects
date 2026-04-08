# 📘 USER DOCUMENTATION

This document explains how to use the Inception infrastructure stack as an end user.

# 🧩 Services Overview

This project provides a complete web stack composed of the following services:

| Service | Description | Access |
|--------|-------------|--------|
| **Nginx** | HTTPS web server (reverse proxy) | https://clalopez.42.fr |
| **WordPress** | Website Content Management System | Browser |
| **MariaDB** | Database server used by WordPress | Internal only |

All services run inside **Docker containers** and communicate through an internal Docker network.


# ▶️ Starting the Project

To start all services, run:

```bash
make
```

This command will:

- Build Docker images
- Create containers
- Start services
- Configure database
- Launch WordPress
- Enable HTTPS

After startup, wait **30–60 seconds** before accessing the website.

---

# ⏹️ Stopping the Project

To stop all services:

```bash
make clean
```

To stop and remove everything (including volumes):

```bash
make fclean
```

To rebuild the project:

```bash
make re
```

# 🌐 Accessing the Website

Open your browser and go to:

```
https://clalopez.42.fr
```

You should see the WordPress website.

⚠️ If your browser shows a security warning, accept it — the SSL certificate is self-signed.

# ⚙️ Accessing WordPress Admin Panel

Open:

```
https://clalopez.42.fr/wp-admin
```

Login using the administrator credentials defined in the `.env` file:

```
WP_ADMIN_USER
WP_ADMIN_PASSWORD
```

From here, you can:

- Create pages
- Install themes
- Add users
- Manage website content


# 🔐 Credentials Location

Sensitive credentials are stored using **Docker Secrets**.

Passwords are located in:

```
secrets/db_root_password.txt
secrets/db_password.txt
```

WordPress users are configured in:

```
srcs/.env
```

Important variables:

```
WP_ADMIN_USER
WP_ADMIN_PASSWORD
MYSQL_USER
MYSQL_DATABASE
```

# 🧪 Checking Services Status

To verify that containers are running:

```bash
docker ps
```

Expected containers:

| Container | Status |
|----------|--------|
| nginx | running |
| wordpress | running |
| mariadb | running |


# 📄 Checking Logs

If something is not working, check logs:

```bash
docker logs nginx
docker logs wordpress
docker logs mariadb
```

Logs help identify:

- Startup errors
- Database connection issues
- Configuration problems


# 🔄 Restarting Services

To restart all containers:

```bash
docker compose restart
```

Or rebuild completely:

```bash
make re
```


# ✅ Verifying Correct Operation

Your stack is working correctly if:

✔ Containers are running  
✔ Website loads in browser  
✔ WordPress admin panel is accessible  
✔ Database connects without errors  

Check:

```bash
docker ps
```

Then open:

```
https://clalopez.42.fr
```


# 🧑‍💻 Administrator Notes

Important directories:

| Path | Purpose |
|------|--------|
| `/home/clalopez/data/mariadb` | Database storage |
| `/home/clalopez/data/wordpress` | WordPress files |
| `secrets/` | Database passwords |
| `srcs/` | Docker configuration |

These directories store **persistent data**.


# 🆘 Troubleshooting

## Website not loading

Check:

```bash
docker ps
```

If containers are not running:

```bash
make re
```


## Database connection error

Check MariaDB logs:

```bash
docker logs mariadb
```


## SSL Warning

This is normal. The certificate is self-signed.

Accept the warning to continue.

# 📌 Summary

This stack provides:

✔ Secure HTTPS website  
✔ WordPress CMS  
✔ MariaDB database  
✔ Persistent storage  
✔ Containerized infrastructure  

Use `make` to start, `make clean` to stop, and access the website through HTTPS.

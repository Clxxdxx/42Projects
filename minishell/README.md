 # 👨🏼‍💻 minishell 👨🏼‍💻

Proyecto creado como parte de 42 Madrid. Esta mini-shell es una implementación de la shell de BASH que soporta redirecciones, pipes, variables de entorno, y builtins principales.

## ✍️ Autores

- **Claudio** — Responsable del parser: análisis léxico, tokenización, manejo de comillas y expansión.
- **Javier** — Responsable del ejecutor: ejecución de comandos, creación de procesos, pipes y redirecciones.

---

## 🌟 Resumen

`minishell` es una shell en C con un enfoque didáctico. Lee líneas de entrada, las parsea en estructuras internas y ejecuta comandos externos o builtins. Está pensada para reproducir el comportamiento básico de shells tipo bash en lo esencial, sin pretender replicar toda su complejidad.

Principales capacidades:

- Productos soportados: ejecución de binarios externos.
- Builtins: `cd`, `echo`, `env`, `exit`, `export`, `pwd`, `unset`.
- Pipes (`|`) y múltiples pipes encadenados.
- Redirecciones: `>`, `>>`, `<` y heredoc (`<<`).
- Expansión de variables de entorno (`$VAR`).
- Manejo de señales (Ctrl-C, Ctrl-\\, etc.) para comportamiento interactivo.

---

## 🏗 Arquitectura

- Parser:
  - Tokeniza la entrada considerando comillas simples y dobles.
  - Maneja expansión de variables y separación de comandos por pipes y redirecciones.
  - Valida la sintaxis básica antes de crear la estructura de ejecución.

- Ejecutor:
  - Construye los procesos hijos y los conecta con pipes según la estructura del parser.
  - Gestiona redirecciones de entrada y salida abriendo/fork/dup2.
  - Ejecuta builtins en el proceso principal cuando corresponde (p. ej. `cd`, `export`).

- Módulos principales:
  - `parser/` — lógica de parsing y expansión.
  - `exec/` — creación de procesos, pipes, redirecciones y lógica de ejecución.
  - `builtins/` — implementaciones de comandos internos.
  - `signals/` — handlers para señales interactivas.
  - `utils_global/` — funciones utilitarias, gestión de memoria y helpers.

---


Ejemplos:

```bash
echo "Hola mundo"
ls -l | grep src | wc -l
cat < file.txt | ./mi_programa > salida.txt
export MYVAR=42
echo $MYVAR
```

---

## ✅ Builtins soportados

- `cd [dir]` — cambia el directorio de trabajo.
- `echo [args]` — imprime argumentos.
- `env` — muestra variables del entorno.
- `export NAME=VALUE` — añade/modifica variables del entorno.
- `unset NAME` — elimina variable del entorno.
- `pwd` — muestra directorio actual.
- `exit [status]` — sale de la shell.

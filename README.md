# 🐚 Minishell

A minimalist Unix shell implementation in C, designed to mimic basic functionalities of the Bash shell.

## 🚀 Features

- **Prompt Display**: Customizable prompt using the `PS1` environment variable.
- **Command Execution**: Supports execution of external commands.
- **Built-in Commands**:
  - `cd` – Change directory.
  - `pwd` – Print working directory.
  - `echo` – Display a line of text.
  - `env` – Display environment variables (includes -i).
  - `export` – Display environment variables.
  - `exit` – Exit the shell.
- **Signal Handling**: Responsive to `Ctrl+C` (SIGINT) and `Ctrl+Z` (SIGTSTP).
- **Process Management**: Handles foreground and background processes.
- **Environment Variables**: Supports `echo $$` and `echo $?` for process ID and exit status.
- **Job Control**: Manages background jobs and process states.

## 🛠️ Installation

1. Clone the repository:

  ```bash
   git clone https://github.com/amakarem/minishell.git
   cd minishell
  ```
   
2. Compile the project:
  ```bash
     make
  ```

3. Run the shell:
  ```
  ./minishell
  ```

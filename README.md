This project has been created as part of the 42 curriculum by cde-la-r.

# Philosophers

## Description

This project is an implementation of the classic "Dining Philosophers" problem, designed to introduce the basics of threading and synchronization in C. The main objective is to understand how to create threads and manage shared resources using mutexes to prevent race conditions and deadlocks.

The simulation consists of a set of philosophers sitting around a circular table. They alternate between eating, thinking, and sleeping. To eat, a philosopher needs two forks. The challenge is to orchestrate these actions without any philosopher starving to death.

## Features

* **Multithreading:** Each philosopher is run as an independent thread.
* **Resource Management (Mutexes):** Forks and shared states (such as printing logs or checking if the simulation should stop) are protected using safe mutex wrappers.
* **Custom Timer:** A precise time tracking system is implemented to monitor the exact moment a philosopher dies or finishes an action.
* **Modular Architecture:** The codebase is divided into specific handlers for actions, mutexes, and core simulation logic to ensure clean resource management and execution.

## Dependencies

* A C compiler (`gcc` or `clang`)
* GNU `make`
* The `pthread` library

## Instructions

1. **Clone the repository**
```bash
git clone https://github.com/cesardelarosa/philosophers.git
cd philosophers

```

2. **Compilation:**
Run the following command at the root of the repository to compile the program using the provided Makefile:

```bash
make

```

3. **Execution:**
The program takes 4 or 5 arguments:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

```

* `number_of_philosophers`: The number of philosophers and forks.
* `time_to_die` (in milliseconds): Time a philosopher can survive without starting to eat.
* `time_to_eat` (in milliseconds): Time it takes for a philosopher to eat.
* `time_to_sleep` (in milliseconds): Time a philosopher spends sleeping.
* `number_of_times_each_philosopher_must_eat` (optional): If all philosophers eat at least this many times, the simulation stops successfully.

4. **Examples:**
```bash
./philo 5 800 200 200
./philo 4 800 200 200 7

```

5. **Cleaning:**
* `make clean`: Removes the object files.
* `make fclean`: Removes the object files and the generated executable.
* `make re`: Cleans and recompiles the project.

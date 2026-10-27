# Workout-Manager

A command-line **Workout Manager** written in C++ in Linux Server for **CMSC 202 – Computer Science II**.

The program allows users to load, display, modify, and manage workouts containing multiple exercises. The project demonstrates linked-list implementation, dynamic memory management, C++ classes, file input, and object-oriented programming.

## Features

- Load workouts and exercises from text files
- Display all available workouts
- Store exercises using a custom linked list
- Reverse the order of exercises in a workout
- Add new exercises to an existing workout
- Create a new workout when adding exercises
- Validate menu selections
- Dynamically allocate and deallocate exercise nodes
- Manage multiple workouts through a `Manager` class

## Data Structure

Each workout is implemented as a **singly linked list**.

An `Exercise` object acts as a node containing:

- Exercise category
- Exercise name
- Number of repetitions
- Weight
- Pointer to the next exercise

The `Workout` class maintains:

- Workout name
- Head pointer
- Tail pointer
- Number of exercises

This allows exercises to be dynamically added and traversed without requiring a fixed-size data structure.

## Project Structure

```text
Workout-Manager/
│
├── Exercise.cpp
├── Exercise.h
├── Workout.cpp
├── Workout.h
├── Manager.cpp
├── Manager.h
├── proj3.cpp
├── makefile
│
├── proj3_workout1.txt
├── proj3_workout2.txt
└── proj3_workout3.txt
```

### `Exercise`

Represents an individual exercise and acts as a node in the linked list.

Each exercise stores:

Category
Exercise Name
Repetitions
Weight
Next Exercise
```

### `Workout`

Represents a workout containing a linked list of `Exercise` objects.

Important functionality includes:

- Adding exercises to the end of the workout
- Accessing exercises
- Reversing the linked list
- Displaying all exercises
- Properly deleting dynamically allocated nodes

### `Manager`

Controls the overall application.

The `Manager` is responsible for:

- Reading workout data from files
- Creating workouts
- Displaying workouts
- Finding existing workouts
- Handling the main menu
- Reversing workouts
- Adding new exercises

The original assignment defines the menu as:

```text
1. Display Workouts
2. Reverse Workouts
3. Insert New Exercise
4. Exit
```

## Input File Format

Workout data is loaded from text files using semicolon-separated values.

Example:

```text
Monday;Back;Barbell Shrug;3;60
Monday;Chest;Bench Press;3;205
Monday;Legs;Toe Raises;3;0
Monday;Back;Deadlift;4;115
Monday;Legs;Seated Leg Press;4;145
```

The fields represent:

```text
Workout Name;Category;Exercise Name;Repetitions;Weight
```

A single file may contain multiple workouts and multiple exercises.

## Building the Project

This project uses a Makefile.

Compile the program with:

```bash
make
```

After compilation, the executable should be named:

```text
proj3
```

## Running the Program

Run the program by providing a workout input file as a command-line argument:

```bash
./proj3 proj3_workout1.txt
```

Other included datasets can also be used:

```bash
./proj3 proj3_workout2.txt
```

```bash
./proj3 proj3_workout3.txt
```

Depending on the Makefile configuration, commands such as the following may also be available:

```bash
make run1
make run2
make run3
```

## Example

When the program starts, it loads the exercises from the selected input file and displays the main menu.

Example:

```text
***Manager***

Opened File
5 exercises loaded across 1 workouts.

What would you like to do?:
1. Display Workouts
2. Reverse Workouts
3. Insert New Exercise
4. Exit
```

Displaying a workout may produce output similar to:

```text
******************
Workout for Monday
5 exercises

Back:Barbell Shrug(3@60lbs)
Chest:Bench Press(3@205lbs)
Legs:Toe Raises(3@0lbs)
Back:Deadlift(4@115lbs)
Legs:Seated Leg Press(4@145lbs)
```

## Reversing a Workout

The program can reverse a workout's linked list in place.

For example:

```text
Barbell Shrug
Bench Press
Toe Raises
Deadlift
Seated Leg Press
```

becomes:

```text
Seated Leg Press
Deadlift
Toe Raises
Bench Press
Barbell Shrug
```

The operation updates both the head and tail pointers of the linked list.

## Adding an Exercise

Users can add an exercise through the menu.

The program requests:

```text
Workout name
Exercise category
Exercise name
Number of repetitions
Weight
```

Example:

```text
What is the name of the workout you would like to insert into?
Monday

What is the category of the exercise?
Legs

What is the name of the exercise?
Squats

How many reps did you do?
3

How much weight did you use? (in lbs.)
0
```

The exercise is then inserted into the selected workout.

## Memory Management

Because the project uses dynamically allocated linked-list nodes, proper memory management is important.

Each dynamically allocated `Exercise` must eventually be deleted.

The program can be checked for memory leaks using **Valgrind**:

```bash
valgrind ./proj3 proj3_workout1.txt
```

A successful run should report:

```text
in use at exit: 0 bytes in 0 blocks
```

This indicates that dynamically allocated memory was successfully released.

## Concepts Demonstrated

This project demonstrates several important C++ and computer science concepts:

- Object-oriented programming
- Classes and objects
- Constructors and destructors
- Getter and setter methods
- Operator overloading
- Linked lists
- Pointers
- Dynamic memory allocation
- File input
- Vectors
- Command-line arguments
- Input validation
- Memory leak detection
- Makefiles

## Technologies

- **C++**
- **GNU Make**
- **G++**
- **Valgrind**
- **Linux / Unix command line**

## Course

**CMSC 202 – Computer Science II**  
University of Maryland, Baltimore County (UMBC)

## Purpose

This project was created as an academic programming project to practice implementing linked data structures and managing dynamically allocated memory in C++.

## Author

**Krish Patel**

## License

This repository is intended for educational and portfolio purposes.

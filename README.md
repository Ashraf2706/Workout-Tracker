# Workout Tracker

## Overview
This project implements a workout tracking application using object-oriented programming principles in C++. It manages exercises within workout sessions and provides functionality to read data from files, dynamically create and manage linked lists of exercises, and display or reverse workouts.

## Features

### Workout Management
1. **Dynamic Workout Creation**:
   - Create and manage multiple workout sessions dynamically.
   - Each workout contains a linked list of exercises.

2. **Exercise Management**:
   - Add exercises to workouts with details such as category, name, reps, and weight.
   - Reverse the order of exercises in a workout.

3. **File Input**:
   - Read and parse workout data from a file.
   - Automatically populate workouts and their exercises from structured input files.

4. **Interactive Menu**:
   - Display all workouts with their exercises.
   - Add new exercises to existing or new workouts.
   - Reverse the exercises in a selected workout.

### Data Structures
- **Linked Lists**:
  - Exercises within a workout are stored in a linked list structure for efficient dynamic memory management.

## Files

### Source Files
1. **`Exercise.cpp` & `Exercise.h`**:
   - Implements the `Exercise` class to represent individual exercises.
   - Attributes: category, name, reps, weight, and a pointer to the next exercise in the list.

2. **`Workout.cpp` & `Workout.h`**:
   - Implements the `Workout` class to represent a session containing exercises.
   - Supports adding exercises, reversing the list, and displaying workout details.

3. **`Manager.cpp` & `Manager.h`**:
   - Implements the `Manager` class to coordinate multiple workouts.
   - Handles file reading, menu navigation, and dynamic memory management.

4. **Input Files**:
   - Example structured data files:
     - **`proj5_test1.txt`**: Contains workouts and their exercises in a structured format.
     - **`proj5_test2.txt`**: Additional test file with similar structure.

### Example Input File Format
Each input file should follow this format:
```
WorkoutName;Category;ExerciseName;Reps;Weight
```
Example:
```
MorningWorkout;Chest;BenchPress;10;200
MorningWorkout;Legs;Squats;15;150
EveningWorkout;Back;PullUps;12;0
```

## Installation and Execution

1. **Compilation**:
   ```bash
   g++ -o workout_tracker Manager.cpp Workout.cpp Exercise.cpp
   ```

2. **Run the Program**:
   ```bash
   ./workout_tracker <input_file>
   ```

## Usage

### Main Menu Options
1. **Display Workouts**:
   - Shows all workouts with their exercises, including reps and weights.

2. **Reverse Workouts**:
   - Allows reversing the order of exercises in a workout.

3. **Insert New Exercise**:
   - Add a new exercise to an existing or new workout.

4. **Exit**:
   - Terminates the program and deallocates all dynamic memory.

### Example Commands
#### Add a New Exercise
```cpp
Manager manager("workouts.txt");
manager.InsertNewExercise();
```

#### Reverse a Workout
```cpp
manager.ReverseWorkout();
```

#### Display Workouts
```cpp
manager.DisplayWorkouts();
```

## Dependencies
- **Standard C++ Libraries**:
  - `<iostream>`
  - `<fstream>`
  - `<string>`
  - `<vector>`

## Classes

### `Exercise` Class
- Represents individual exercises.
- **Attributes**:
  - Category (e.g., Chest, Legs).
  - Name (e.g., Bench Press).
  - Reps (e.g., 10).
  - Weight (e.g., 200 lbs).
  - Pointer to the next exercise in the list.
- **Methods**:
  - Getters and setters for all attributes.
  - Overloaded `<<` operator for displaying exercise details.

### `Workout` Class
- Represents a session of exercises.
- **Attributes**:
  - Name of the workout.
  - Linked list of exercises.
- **Methods**:
  - Insert exercises at the end.
  - Reverse the list of exercises.
  - Display workout details.

### `Manager` Class
- Manages multiple workout sessions.
- **Attributes**:
  - Vector of pointers to workouts.
- **Methods**:
  - Read workout data from a file.
  - Insert new exercises dynamically.
  - Display or reverse workouts.

## Authors
- **Ashraf Kawooya**
- **Date**: Fall 2023

## License
This project is for educational purposes and does not include warranties or guarantees.

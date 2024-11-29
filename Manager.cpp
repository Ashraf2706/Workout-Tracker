#include "Manager.h"

// Name: Manager (constructor)
// Desc: Creates a Manager to manage workouts 
// Preconditions:  None
// Postconditions: A manager is created to populate m_workouts
Manager::Manager(string fileName){
  m_fileName = fileName;
  ReadFile(); //calls the ReadFile function
  MainMenu(); // calls the MainMenu function
}

// Name:  Manager (destructor)
// Desc: Deallocates all dynamic aspects of a Manager
// Preconditions: There is an existing Workout
// Postconditions: All workouts are cleared
Manager::~Manager(){
  cout << "Deleting Workouts" << endl;
  for(unsigned int i = 0; i < m_workouts.size(); i++){
    delete m_workouts[i]; // Deallocates memory from each workout
  }
}

// Name:  DisplayWorkouts
// Desc: Displays each workout in m_workouts
// Preconditions: At least one workout is in m_workouts
// Postconditions: Displays all items in a workout for all
//                 workouts in m_workouts
void Manager::DisplayWorkouts(){
  int workoutCount = 0;
  if(m_workouts.size() > 0){
    for(unsigned int i = 0; i < m_workouts.size(); i++){
      workoutCount++;
      cout << *m_workouts[i]; //Displays each workout
    }
  }
}

// Name:  ReadFile
// Desc: Reads in a file that has each part of the workout
//       Starts with category, name, reps, and weight.
//       Input files are an indeterminate length.
//       There are an indeterminate number of workouts in
//       an input file.
//       There are an indeterminate number of exercises in each file.
//       The vector can hold many workouts.
// Preconditions: Valid file name of workouts
// Postconditions: Populates each workout and puts in m_workouts
void Manager::ReadFile(){
  string workoutName;
  string category;
  string exerciseName;
  string reps;
  string weight;
  int intReps = 0;
  int intWeight = 0;
  int exerciseCount = 0;
  int workoutCount = 0;

  ifstream myfile(m_fileName);
  if(myfile.is_open()){
    while(getline(myfile, workoutName, ';')){
      getline(myfile, category, ';');
      getline(myfile, exerciseName, ';');
      getline(myfile, reps, ';');
      getline(myfile, weight);

      intReps = stoi(reps);
      intWeight = stoi(weight);

      if(FindWorkout(workoutName) == -1){
        // Create a new Workout object for the first workout
        Workout* newWorkout = new Workout(workoutName);
        m_workouts.push_back(newWorkout); // adds workout to the m_workouts
        workoutCount++;
      }
      Exercise* newExercise = new Exercise(category, exerciseName, intReps, intWeight);
      // Create a new Exercise object for the exercises
      m_workouts[FindWorkout(workoutName)]->InsertEnd(newExercise); // adds the respective exercises for each workout
      exerciseCount++;
    }
    myfile.close();
  }else{
    cout << "Failed to open file" << endl;
  }
 cout << exerciseCount << " exercises loaded across " << workoutCount << " workouts." << endl;
}

// Name: InsertNewExercise
// Desc: Asks the user which workout they would like to insert into (uses FindWorkout)
//       If new workout, inserts a new workout and indicates a new workout was created
//       Prompts user for time and name of item then inserts item into workout
// Preconditions: Populated m_workouts
// Postconditions: Either inserts into existing workout or inserts into a new workout
void Manager::InsertNewExercise(){
  string workoutName;
  int workoutIndex;

  cout << "What is the name of the workout you would like to insert into?" << endl;
  cin >> workoutName;

  workoutIndex = FindWorkout(workoutName);//sets the index of the respective workout

  if(workoutIndex == -1){ // if the workout is non existant
    Workout* newWorkout = new Workout(workoutName); // creates a new workout object
    m_workouts.push_back(newWorkout); // adds the new workout
    workoutIndex = m_workouts.size() - 1;
  }
  Exercise* newExercise;
  string category, name;
  int reps, weight;

  cout << "What is the category of the exercise?" << endl;
  cin >> category;
  cout << "What is the name of the exercise?" << endl;
  cin >> name;
  cout << "How many reps did you do?" << endl;
  cin >> reps;
  cout << "How much weight did you use? (in lbs.)" << endl;
  cin >> weight;

  newExercise = new Exercise(category, name, reps, weight);
  m_workouts[workoutIndex]->InsertEnd(newExercise); // adds the respective exercises for the added workout
}

// Name: FindWorkout
// Desc: Returns the index of the workout from m_workouts else -1
// Preconditions: Populated m_workouts
// Postconditions: Returns the index of workout with the matching name or it returns -1
int Manager::FindWorkout(string schedName){
  for(unsigned int i = 0; i < m_workouts.size(); i++){
    if(m_workouts[i] -> GetName() == schedName){
      return i;
    }
  }
  return -1; 
}

// Name:  MainMenu
// Desc: Displays the main menu and manages exiting
// Preconditions: Populated m_workouts
// Postconditions: None
void Manager::MainMenu(){
  int choice;


  while(choice != 4){
    cout << "What would you like to do?" << endl;
    cout << "1. Display Workouts" << endl;
    cout << "2. Reverse Workouts" << endl;
    cout << "3. Insert New Exercise" << endl;
    cout << "4. Exit" << endl;

    cin >> choice;
    cout << endl;

    switch (choice){
      case 1:
        DisplayWorkouts();
        break;
      case 2:
        ReverseWorkout();
        break;
      case 3:
        InsertNewExercise();
        break;
      case 4:
        cout << "Workouts removed from memory" << endl;
        break;
      default:
        break;
    }
  }
}

// Name: ReverseWorkout
// Desc: User chooses a workout and the workout is reversed
//       If only one workout in m_workouts, automatically reverses it without prompting the user
// Preconditions: Populated m_workouts
// Postconditions: Reverses a specific workout replacing in place
void Manager::ReverseWorkout(){
  long unsigned int workInput = 0;
  bool reverseFlag = true;
  bool workoutFlag = true;

  while(reverseFlag){
    if(m_workouts.size() == 1){// if only one workout is being reversed
      m_workouts[0]->ReverseWorkout();
      cout << "Done reversing Workout 1" << endl;
      reverseFlag = false; // ends the function
    }else{
      while(workoutFlag){
        cout << "Which workout to reverse?" << endl;
        cout << "Choose 1 - " << m_workouts.size() << endl; // if more than one workout
        cin >> workInput;
        if(workInput >= 1 || workInput <= m_workouts.size()){
          m_workouts[workInput - 1]->ReverseWorkout();
          cout << "Done reversing Workout " << workInput << endl;
          workoutFlag = false;
          reverseFlag = false;
        } 
      }
    }
  }
}
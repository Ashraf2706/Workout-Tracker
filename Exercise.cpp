#include "Exercise.h"

// Name: Exercise (default constructor)
// Desc: Default constructor for Exercise
// Preconditions: None
// Postconditions: Creates a new Exercise 
// Note: May not be used in project 3 but still implement
Exercise::Exercise(){
  m_category = "";
  m_name = "";
  m_reps = 0;
  m_weight = 0;
  m_next = nullptr;
}

// Name: Exercise (overloaded constructor)
// Desc: Sets values of a new Exercise (an exercise is a node in a linked list)
//       Category, name, reps, and weight.
// Preconditions: None
// Postconditions: Creates a new node using the category, name, reps, and weight
Exercise::Exercise(string category, string name, int reps, int weight){
  m_category = category;
  m_name = name;
  m_reps = reps;
  m_weight = weight;
  m_next = nullptr;
}

// Name: GetCategory
// Desc: Returns the category of the exercise
// Preconditions: Exercise must exist
// Postconditions: Returns the category of the exercise
string Exercise::GetCategory(){
  return m_category;
}

// Name: GetName
// Desc: Returns the name of the exercise
// Preconditions: Exercise must exist
// Postconditions: Returns the name of the exercise
// Note: May not be used in project 3 but still implement
string Exercise::GetName(){
  return m_name;
}

// Name: GetReps
// Desc: Returns the number of reps of the exercise
// Preconditions: Exercise must exist
// Postconditions: Returns the number of reps of the exercise
// Note: May not be used in project 3 but still implement
int Exercise::GetReps(){
  return m_reps;
}

// Name: GetWeight
// Desc: Returns the weight of the exercise
// Preconditions: Exercise must exist
// Postconditions: Returns the weight of the exercise
// Note: May not be used in project 3 but still implement
int Exercise::GetWeight(){
  return m_weight;
}

// Name: GetNext
// Desc: Returns the pointer to the next exercise
// Preconditions: Exercise must exist
// Postconditions: Returns the pointer to the next exercise
// Note: May not be used in project 3 but still implement
Exercise* Exercise::GetNext(){
  return m_next;
}

// Name: SetCategory
// Desc: Sets the category of the exercise
// Preconditions: Exercise must exist
// Postconditions: Sets the category of the exercise
// Note: May not be used in project 3 but still implement
void Exercise::SetCategory(string category){
  m_category = category;
}

// Name: SetName
// Desc: Sets the name of the exercise
// Preconditions: Exercise must exist
// Postconditions: Sets the name of the exercise
// Note: May not be used in project 3 but still implement
void Exercise::SetName(string name){
  m_name = name;
}

// Name: SetReps
// Desc: Sets the number of reps of the exercise
// Preconditions: Exercise must exist
// Postconditions: Sets the reps of the exercise
// Note: May not be used in project 3 but still implement
void Exercise::SetReps(int reps){
  m_reps = reps;
}

// Name: SetWeight
// Desc: Sets the weight (in lbs) of the exercise
// Preconditions: Exercise must exist
// Postconditions: Sets the weight of the exercise
// Note: May not be used in project 3 but still implement
void Exercise::SetWeight(int weight){
  m_weight = weight;
}

// Name: SetNext
// Desc: Sets the next exercise
// Preconditions: Exercise must exist
// Postconditions: Sets the next exercise
// Note: May not be used in project 3 but still implement
void Exercise::SetNext(Exercise* next){
  m_next = next;
}

// Name: operator<<
// Desc: Overloaded << operator to return ostream from an Exercise
// Preconditions: Requires an Exercise
// Postconditions: Returns ostream with name, reps, and weight
// **PROVIDED** Do not edit

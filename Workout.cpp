#include "Workout.h"

// Name: Workout() - Default Constructor
// Desc: Used to build a new Workout 
// Preconditions: None
// Postconditions: Creates a new Workout where m_head and
//                 m_tail point to nullptr and size = 0
Workout::Workout(){
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
  m_name = "";
}

// Name: Workout(string) - Overloaded Constructor
// Desc: Used to build a new Workout with the workout name passed
// Preconditions: None
// Postconditions: Creates a new Workout where m_head and m_tail point
//                 to nullptr and workout name is passed
Workout::Workout(string name){
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
  m_name = name;
}

// Name: ~Workout() - Destructor
// Desc: Used to destruct a strand of Workout
// Preconditions: There is an existing Workout strand with at least one node
// Postconditions: Workout is deallocated to have no memory leaks
//                 (including all dynamically allocated nodes)
Workout::~Workout(){
  Exercise *current = m_head;
  //iterate through and remove each exercise
  while(current != nullptr){
    m_head = current; //set m_head to current
    current = current -> GetNext(); //moves current to m_next;
    delete m_head; //deletes m_head
  }
  //resets all pointers
  m_name = "";
  m_head = nullptr; //sets m_head to null
  m_tail = nullptr; // sets m_tail to null
  m_size = 0; //sets m_size to 0
  delete current; //deletes current
}

// Name: InsertEnd
// Desc: Inserts a new item to the end of the workout using m_tail.
// Preconditions: Takes in an Exercise pointer. Inserts the new node to the tail.
//                Requires a Workout
// Postconditions: Adds the new item into the Workout.
void Workout::InsertEnd(Exercise* newExercise){
  //if the exercise added is first exercise, then set head and tail to new exercise
  if(m_head == nullptr){
    m_head = newExercise;
    m_tail = newExercise;
    m_size++;
  }else{
    //if exercise added is not first then set new tail with new exercise
    m_tail->SetNext(newExercise);
    m_tail = newExercise;
    m_size++;
  }
}

// Name: GetName()
// Preconditions: Requires a Workout
// Postconditions: Returns m_name;
string Workout::GetName(){
  return m_name;
}

// Name: GetSize()
// Preconditions: Requires a Workout
// Postconditions: Returns m_size;
int Workout::GetSize(){
  return m_size;
}

// Name: ReverseWorkout
// Preconditions: Reverses the Workout (updates m_head and m_tail)
//                Updates the pointers only - does not create a new list
// Postconditions: Workout is reversed in place; nothing returned
void Workout::ReverseWorkout(){
  Exercise *head = m_head;
  Exercise *tail = m_tail;
  Exercise *current = m_head;
  Exercise *previous = nullptr;
  Exercise *next;

  while(current != nullptr){
    next = current -> GetNext();
    current -> SetNext(previous);
    previous = current;
    current = next;
  }
  m_head = tail;
  m_tail = head;
}

// Name: GetData
// Desc: Returns the time at a specific location in the Workout
//       Pass 
// Preconditions: Requires a Workout
// Postconditions: Returns data from specific item
// Note: May not be used in project but still required
Exercise* Workout::GetData(int nodeNum){
  Exercise* temp = m_head;

  for(int i = 0; i < nodeNum; i++){
    temp = temp -> GetNext();//set temp to next until loop ends
  }
  return temp;
}

// Name: operator<<
// Desc: Allows you to cout a Workout object
//       Overloaded << operator to return ostream from Workout
//       Should not have any cout statements!
// Preconditions: Requires a Workout sequence
// Postconditions: Returns ostream populated for each Exercise in Workout
ostream &operator<< (ostream &output, Workout &myWorkout){
  cout << "*****************" << endl;
  output << "Workout for " << myWorkout.GetName() << endl;
  output << myWorkout.GetSize() << " exercises" << endl;
  for(int i = 0; i < myWorkout.GetSize(); i++){
      output << *(myWorkout.GetData(i)) << endl;
  }
  cout << endl;
  return output;
}
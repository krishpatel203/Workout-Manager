#include "Workout.h"

// Name: Workout() - Default Constructor                                                                                                                                                                  
  // Desc: Used to build a new Workout                                                                                                                                                                      
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Creates a new Workout where m_head and                                                                                                                                                 
  //                 m_tail point to nullptr and size = 0                                                                                                                                                   
Workout::Workout(){
   // Initialize the name 
   m_name = "";

   // Initialize the head
   m_head = nullptr;

   // // Initialize the tail
   m_tail = nullptr;

   // // Initialize the size
   m_size = 0;
}
  // Name: Workout(string) - Overloaded Constructor                                                                                                                                                         
  // Desc: Used to build a new Workout with the workout name passed                                                                                                                                         
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Creates a new Workout where m_head and m_tail point                                                                                                                                    
  //                 to nullptr and workout name is passed                                                                                                                                                  
Workout:: Workout(string name){
  // Set the name
  m_name = name;

  //Initialize the head   
  m_head = nullptr;

  //Initialize the tail
  m_tail = nullptr;

  //Initialize the size
  m_size = 0;
}
  // Name: ~Workout() - Destructor                                                                                                                                                                          
  // Desc: Used to destruct a strand of Workout                                                                                                                                                             
  // Preconditions: There is an existing Workout strand with at least one node                                                                                                                              
  // Postconditions: Workout is deallocated to have no memory leaks                                                                                                                                         
  //                 (including all dynamically allocated nodes)                                                                                                                                            
Workout:: ~Workout(){
   //while loop
   while (m_head != nullptr) {
        // Store a pointer
        Exercise* temp = m_head;

	// Update 'm_head' to the next Exercise
        m_head = m_head->GetNext();

	// Delete the Exercise
        delete temp;
    }
}
  // Name: InsertEnd                                                                                                                                                                                        
  // Desc: Inserts a new item to the end of the workout using m_tail.                                                                                                                                       
  // Preconditions: Takes in an Exercise pointer. Inserts the new node to the tail.                                                                                                                         
  //                Requires a Workout                                                                                                                                                                      
  // Postconditions: Adds the new item into the Workout.                                                                                                                                                    
void Workout::InsertEnd(Exercise* newWorkout){
  if (m_tail == nullptr) {
        // If the Workout is empty, set both head
        m_head = newWorkout;

	//set tail to the new Exercise   
        m_tail = newWorkout;
    } else {
        // Otherwise, append the new Exercise
        m_tail->SetNext(newWorkout);
        m_tail = newWorkout;
    }
    m_size++;
}
  // Name: GetName()                                                                                                                                                                                        
  // Preconditions: Requires a Workout                                                                                                                                                                      
  // Postconditions: Returns m_name;                                                                                                                                                                        
string Workout::GetName(){
  //return m_name
  return m_name;
}
  // Name: GetSize()                                                                                                                                                                                        
  // Preconditions: Requires a Workout                                                                                                                                                                      
  // Postconditions: Returns m_size;                                                                                                                                                                        
int Workout::GetSize(){
  //return m_size
  return m_size;
}
// Name: ReverseWorkout                                                                                                                                                                                   
  // Preconditions: Reverses the Workout (updates m_head and m_tail)                                                                                                                                        
  //                Updates the pointers only - does not create a new list                                                                                                                                  
  // Postconditions: Workout is reversed in place; nothing returned                                                                                                                                         
void Workout::ReverseWorkout(){
    // Initialize three pointers
    Exercise* pre = nullptr;
    Exercise* curr = m_head;
    Exercise* nxt = nullptr;

    //Set the 'm_tail
    m_tail = m_head;

    //while loop
    while (curr != nullptr) {
        // Store the next Exercise
        nxt = curr->GetNext();

	// Reverse the 'next' pointer to point
        curr->SetNext(pre);

	//Move 'pre'
        pre = curr;

	// Move curr
        curr = nxt;
    }

    // Update 'm_head' to point to the last Exercise, which is now the first.
    m_head = pre;
}
  // Name: GetData                                                                                                                                                                                          
  // Desc: Returns the time at a specific location in the Workout                                                                                                                                           
  //       Pass                                                                                                                                                                                             
  // Preconditions: Requires a Workout                                                                                                                                                                      
  // Postconditions: Returns data from specific item                                                                                                                                                        
  // Note: May not be used in project but still required                                                                                                                                                    
Exercise* Workout::GetData(int nodeNum){
  //if statement
  if (nodeNum < 0 || nodeNum >= m_size) {
        // Invalid node number     
        return nullptr;
    }

    //Workout list to find the Exercise
    Exercise* curr = m_head;

    //for loop
    for (int i = 0; i < nodeNum; i++) {
        curr = curr->GetNext();
    }

    //return
    return curr;
}
  // Name: operator<<                                                                                                                                                                                       
  // Desc: Allows you to cout a Workout object                                                                                                                                                              
  //       Overloaded << operator to return ostream from Workout                                                                                                                                            
  //       Should not have any cout statements!                                                                                                                                                             
  // Preconditions: Requires a Workout sequence                                                                                                                                                             
  // Postconditions: Returns ostream populated for each Exercise in Workout                                                                                                                                 
ostream &operator<< (ostream &output, Workout &myWorkout){
    // Initialize a pointer
    Exercise* curr = myWorkout.m_head;

    //while loop
    while (curr != nullptr) {
      // Assuming Exercise class has an overloaded << operator    
      output << *curr << endl;

      //curr GetNext
      curr = curr->GetNext();
    }

    //return output
    return output;
}

#include "Manager.h"

// Name: Manager (constructor)                                                                                                                                                                            
  // Desc: Creates a Manager to manage workouts                                                                                                                                                             
  // Preconditions:  None                                                                                                                                                                                   
  // Postconditions: A manager is created to populate m_workouts                                                                                                                                            
Manager::Manager(string fileName){

    //Set the member variable m_fileName
    m_fileName = fileName;

    //Call ReadFile
    ReadFile();

    //Call MainMenu
    MainMenu();
}
  // Name:  Manager (destructor)                                                                                                                                                                            
  // Desc: Deallocates all dynamic aspects of a Manager                                                                                                                                                     
  // Preconditions: There is an existing Workout                                                                                                                                                            
  // Postconditions: All workouts are cleared                                                                                                                                                               
Manager:: ~Manager(){

  //for loop
  for (Workout* workout : m_workouts) {
    
    //Deallocate dynamic memory for workouts 
       delete workout;
    }
}
  // Name:  DisplayWorkouts                                                                                                                                                                                 
  // Desc: Displays each workout in m_workouts                                                                                                                                                              
  // Preconditions: At least one workout is in m_workouts                                                                                                                                                   
  // Postconditions: Displays all items in a workout for all                                                                                                                                                
  //                 workouts in m_workouts                                                                                                                                                                 
void Manager::DisplayWorkouts(){
  // Display a line of asterisks
    cout << "******************" << endl;

  //Loop through m_workouts
  for (size_t i = 0; i < m_workouts.size(); i++) {
        Workout* currentWorkout = m_workouts[i];

	//Display the workout name
        cout << "Workout " << "for " << currentWorkout->GetName() << endl;

	// Display the number of exercises 
        cout << currentWorkout->GetSize() << " exercises" << endl;

	// Display the details of the workout
	cout << *currentWorkout << endl;

	//cout endl;
        cout << endl;
    }
       
  
   //if statement
   if (m_workouts.empty()) {

        //No workout to display
        cout << "No workouts to display." << endl;

        return;
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
  //Open the input file 
  ifstream inputFile(m_fileName);   

    //if statement if file does not open
    if (!inputFile.is_open()) {
        //cout message if file does not open the file
        cout << "Failed to open the input file: " << m_fileName << endl;

	//return
        return;

    //else statement
    } else {
        //cout open file
        cout << "Opened File" << endl;
    }

    //int to count the total number of exercises  
    int totalExer = 0;

    //int total workout
    int workoutCount = 0;

    //string name and category
    string category, name;

    //string reps and weight
    string reps, weight;

    //string day
    string day;

    //while to read data and remove semicolan
    while (getline(inputFile, day, ';') && getline(inputFile, category, ';') && getline(inputFile, name, ';') && getline(inputFile, reps, ';') && getline(inputFile ,weight)) {
            //Find the index of the workout
            int workoutIndex = FindWorkout(day);

	    //if workout does not exist
            if (workoutIndex == -1) {
	        //create a new workout
                Workout* newWorkout = new Workout(day);

		//create a new exercise
		Exercise* newExercise = new Exercise(category, name, stoi(reps), stoi(weight));

		//Add exercise to workout
                newWorkout->InsertEnd(newExercise);

		// Increment the total exercise count 
                totalExer++;
                
		//pusch back m_workout
                m_workouts.push_back(newWorkout);

		//Increment the workout count   
                workoutCount++;
            }

	    //else statment
	    else {
	        //Get the existing workout
                Workout* existingWorkout = m_workouts[workoutIndex];

                // Create a new exercise
		Exercise* newExercise = new Exercise(category, name, stoi(reps), stoi(weight));

		//Add the exercise to the existing workout
                existingWorkout->InsertEnd(newExercise);

		// Increment the total exercise count    
                totalExer++;
                }
            }
        
    //close the file
    inputFile.close();

    // Print the summary message after processing the file
    cout << totalExer << " exercises loaded across " << workoutCount << " workouts." << endl;  
  }

// Name: InsertNewExercise                                                                                                                                                                                
  // Desc: Asks the user which workout they would like to insert into (uses FindWorkout)                                                                                                                    
  //       If new workout, inserts a new workout and indicates a new workout was created                                                                                                                    
  //       Prompts user for time and name of item then inserts item into workout                                                                                                                            
  // Preconditions: Populated m_workouts                                                                                                                                                                    
  // Postconditions: Either inserts into existing workout or inserts into a new workout                                                                                                                    //This function is FINISHED 
void Manager::InsertNewExercise(){
  //string wrkme
  string wrkNme;

  //prompt the name of workout
  cout << "What is the name of the workout you would like to insert into?" << endl;

  //prompt user for name
  cin >> wrkNme;

  //Find the index of the workout
  int index = FindWorkout(wrkNme);

  //if statement
  if (index == -1) {
        // Workout not found, create a new workout
        Workout* newWorkout = new Workout(wrkNme);

	//Add the new workout
        m_workouts.push_back(newWorkout);

	//Update the index to point 
        index = m_workouts.size() - 1;
    }

  //string category
  string category;

  //string name
  string name;

  //int reps
  int reps;

  //double weight
  double weight;

  //cout what is the category of the exercise
  cout << "What is the category of the exercise?" << endl;
  
  cin >> category;

  //cout what is the name of the exercise
  cout << "What is the name of the exercise?" << endl;
  
  cin >> name;

  //How many reps did you do
  cout << "How many reps did you do?" << endl;
  
  cin >> reps;

  //How much weight did you use (in lbs)
  cout << "How much weight did you use? (in lbs.)" << endl;
  
  cin >> weight;

  //Create a new exercise 
  Exercise* newExer = new Exercise(category, name, reps, weight);

  // Add the new exercise 
  m_workouts[index]->InsertEnd(newExer);

}
  // Name: FindWorkout                                                                                                                                                                                      
  // Desc: Returns the index of the workout from m_workouts else -1                                                                                                                                         
  // Preconditions: Populated m_workouts                                                                                                                                                                    
  // Postconditions: Returns the index of workout with the matching name or it returns -1                                                                                                                  //This function is FINISHED 
int Manager::FindWorkout(string schedName){
  //for loop
  for (int i = 0; i < m_workouts.size(); i++) {

        //if statement
        if (m_workouts[i]->GetName() == schedName) {
	    //return i
            return i;
        }
    }

    // return -1
    return -1;
}
  // Name:  MainMenu                                                                                                                                                                                        
  // Desc: Displays the main menu and manages exiting                                                                                                                                                       
  // Preconditions: Populated m_workouts                                                                                                                                                                    
  // Postconditions: None                                                                                                                                                                                   //This function is FINISHED
void Manager::MainMenu(){
  //int choice
  int choice;

  //while loop
  while (true) {
        //what would you like to do?
        cout << "What would you like to do?:" << endl;

	//display workouts
        cout << "1. Display Workouts" << endl;

	//reverse workout
        cout << "2. Reverse Workouts" << endl;

	//insert the newn exercise
        cout << "3. Insert New Exercise" << endl;

	//exit
        cout << "4. Exit" << endl;
	
        cin >> choice;

	//switch choice
        switch (choice){
	   //case 1
            case 1:
	        //DisplayWorkout
                DisplayWorkouts();

		//break
                break;

	    //case2
            case 2:
	        //ReverseWorkout
	        ReverseWorkout();

		//break
                break;

	     //case 3
            case 3:
	        //InsertNewExercise
	        InsertNewExercise();

		//breaj
                break;

	     //case 4
            case 4:
	      cout << "Workouts removed from memory" << endl;
	      cout << "Deleting Workouts" << endl;
	      return;
	      
            default:
	        //invalid choice
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
  // Name: ReverseWorkout                                                                                                                                                                                   
  // Desc: User chooses a workout and the workout is reversed                                                                                                                                               
  //       If only one workout in m_workouts, automatically reverses it without prompting the user                                                                                                          
  // Preconditions: Populated m_workouts                                                                                                                                                                    
  // Postconditions: Reverses a specific workout replacing in place                                                                                                                                         
void Manager::ReverseWorkout(){
  //if m_workouts empty
  if (m_workouts.empty()) {
    //no workout to reverse
    cout << "No workouts available to reverse." << endl;

    //return
    return;
}

//if statement
if (m_workouts.size() == 1) {
    // If there's only one workout, reverse it automatically
    m_workouts[0]->ReverseWorkout();

    //cout else done reversing workout
    cout << "Done reversing Workout." << endl;

    //else statement  
} else {
    //cout a workout to reverse
    cout << "Choose a workout to reverse:" << endl;

    // Display available workouts and let the user choose
    for (unsigned int i = 0; i < m_workouts.size(); i++) {
        //Display a list of available workouts
        cout << i + 1 << ". " << m_workouts[i]->GetName() << endl;
    }

    int unsigned choice;  // Change choice to an unsigned integer

    //cout the number of workout you want to reverse
    cout << "Enter the number of the workout you want to reverse: ";
    
    cin >> choice;

    //if statement
    if ( choice >= 1 && choice <= m_workouts.size()) {
        // Valid workout selection
        m_workouts[choice - 1]->ReverseWorkout();

	//else done reversing workout
        cout << "Done reversing Workout." << endl;

     //else statement
    } else {
        //invalid workout
        cout << "Invalid workout selection." << endl;
    }
 }
}

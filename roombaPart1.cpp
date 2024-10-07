#include <iostream>
#include <limits> // Using this header to limit char direction input to one charcter
using namespace std;

// Starting point of Roomba is set to (0,0)
int locationX = 0;
int locationY = 0;
char direction;

void roombaLocation();
void userKeyInput();
void moveN();
void moveForwardToWallN();
void moveS();
void moveForwardToWallS();
void moveE();
void moveForwardToWallE();
void moveW();
void moveForwardToWallW();

int main()
{   
    unsigned enter;
    cout << "Welcome to the Roomba Simulator!\n\n";
    cout << "Here are the controls:\n";
    cout << "n =  move the robot forward (to the north) one step" << endl;
    cout << "s =  move the robot backward (to the south) one step" << endl;
    cout << "e =  move the robot right (to the east) one step" << endl;
    cout << "w =  move the robot left (to the west) one step\n" << endl;

    cout << "N =  move the robot to the wall (north)" << endl;
    cout << "S =  move the robot to the wall (south)" << endl;
    cout << "E =  move the robot to the wall (east)" << endl;
    cout << "W =  move the robot to the wall (west)\n"  << endl;

    cout << "q =  Quit the program\n" << endl;

    cout << "Let's begin! (Press any key) ";
    cin.ignore();
    cout << "\n";

    roombaLocation();
    while(direction != 'q'){
    userKeyInput();

    }
    cout << endl << "Program terminated" << endl << "Thank you for playing the Roomba Simulator!"; 


    return 0;
}

// Displays roomba's location at any given moment 
void roombaLocation(){
    cout << "The roomba is at location (" << locationX << ", " << locationY << ")" << endl;
}

// Receives user input for direction //
void userKeyInput(){
    cout << "enter direction: ";
    cin >> direction;

    /* peek returns the next character from input, if next input is not a new line meaning 
    if theres more than 1 character entered, invalid, else-carry on with program */
    if(cin.peek() != '\n'){
        cout << "More than one character entered. Re-";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        userKeyInput();
    } else{
        if(direction == 'n'){
            moveN();
        } else if(direction == 'N'){
            moveForwardToWallN();
        } else if(direction == 's'){
            moveS();
        } else if(direction == 'S'){
            moveForwardToWallS();
        } else if(direction == 'e'){
            moveE();
        } else if(direction == 'E'){
            moveForwardToWallE();
        } else if(direction == 'w'){
            moveW();
        } else if(direction == 'W'){
            moveForwardToWallW();
        } else if(direction == 'q'){
            
        } else {
            cout << "Unrecognized input, re-";
            userKeyInput();
        }
    }
}

// Makes the roombot move forward (North) by one, increasing locationY by 1 //
void moveN(){
    if((locationY + 1) > 9){
        cout << "Roomba can't go beyond scope, re-";
        userKeyInput();
    } else if((locationY + 1) == 9){
        cout << "moving forward..." << endl;
        locationY++;
        roombaLocation();
        cout << "Roomba has bumped against the wall!" << endl;
    } else{
        cout << "moving forward..." << endl;
        locationY++;
        roombaLocation();
        
    }
}

// Roombot moves to the wall, North//
void moveForwardToWallN(){
    if(locationY == 9){
        cout << "The roomba is already at the wall! Re-";
    } else{
        locationY = 9;
        roombaLocation();
        cout << "Roomba has bumped against the wall!" << endl;
    }
}

// Makes the roombot move backward (South) by one, increasing locationY by 1 //
void moveS(){
    if((locationY - 1) < 0){
        cout << "Roomba can't go beyond scope, re-";
        userKeyInput();
    } else if((locationY - 1) == 0){
        cout << "moving backward..." << endl;
        --locationY;
        roombaLocation();
        cout << "Roomba has bumped against the wall!" << endl;
    } else{
        cout << "moving backward..." << endl;
        --locationY;
        roombaLocation();
        
    }
}

// Roombot moves to the wall, North//
void moveForwardToWallS(){
     if(locationY == 0){
        cout << "The roomba is already at the wall! Re-";
    } else{
        locationY = 0;
        roombaLocation();
        cout << "Roomba has bumped against the wall!" << endl;
    }  
}

// Makes the roombot move forward (East) by one, increasing locationX by 1 //
void moveE(){
    if((locationX + 1) > 9){
        cout << "Roomba can't go beyond scope, re-";
        userKeyInput();
    } else if((locationX + 1) == 9){
        cout << "moving right..." << endl;
        locationX++;
        roombaLocation();
        cout << "Roomba has bumped against the wall!" << endl;
    } else{
        cout << "moving right..." << endl;
        locationX++;
        roombaLocation();
        
    }
}

// Roombot moves to the wall, East//
void moveForwardToWallE(){
    if(locationX == 9){
        cout << "The roomba is already at the wall! Re-";
    } else{
        locationX = 9;
        roombaLocation();
        cout << "Roomba has bumped against the wall!" << endl;
    }
}

// Makes the roombot move forward (West) by one, decreasing locationX by 1 //
void moveW(){
    if((locationX - 1) < 0){
        cout << "Roomba can't go beyond scope, re-";
        userKeyInput();
    } else if((locationX - 1) == 0){
        cout << "moving left..." << endl;
        --locationX;
        roombaLocation();
        cout << "Roomba has bumped against the wall!" << endl;
    } else{
        cout << "moving left..." << endl;
        --locationX;
        roombaLocation();
        
    }
}

// Roombot moves to the wall, West//
void moveForwardToWallW(){
    if(locationX == 0){
        cout << "The roomba is already at the wall! Re-";
    } else{
        locationX = 0;
        roombaLocation();
        cout << "Roomba has bumped against the wall!" << endl;
    }
}




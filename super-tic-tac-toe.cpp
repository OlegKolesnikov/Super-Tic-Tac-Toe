#include <iostream> 
#include <string> 
#include <windows.h>   // required tor colored text
#include <time.h>       // required for random number generator 
#include <winuser.h>
#include <mmsystem.h> // play sound
#include<stdlib.h>
#include<thread>
#include <mmsystem.h>

using namespace std ; 

void colorfulstring ();
int DisplayResourceNAMessageBox();
string input ( int player ) ; 
void update ( string players_Choice , int player , string game_board [ ] ) ;
void output ( string game_board [ ] ,string choice) ;
int string_To_Number ( string choice ) ;
void colorful_String (string original);
void check_Winner ( string game_Board [ ] ) ;
void song1 ();
void song2 ();




int main ( int argc, char* argv[]) 
{
    colorfulstring ();
  
    song1 ();
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string game_Board [ 17 ] = { "[A] ","[B] ","[C] ","[D] ","[E] ","[F] ","[G] ","[H] ","[I] ","[J] ","[K] ","[L] ","[M] ","[N] ","[O] ","[P] " } ;
    string players_Choice ; 
    int player = 1 ;

    SetConsoleTextAttribute(hConsole, 9); //# Sets color of text to blue 
    cout<< "\n   WELCOME TO \n     SUPER\n  TIC TAK TOW \n   HAVE FUN!!\n\n" ;
    
    string choice = "print";

    while ( true )
    { 
        output ( game_Board,choice ) ;
        SetConsoleTextAttribute(hConsole, 14); //# Sets color of text to Yellow
        players_Choice = input ( player ) ;
        
        update ( players_Choice , player , game_Board ) ;

        player ++ ;
        DisplayResourceNAMessageBox();
    }

    return 0 ;
}

void song1 ()
{
    Beep(261.6256 ,500);//c
    Beep(293.6648 ,500);//d
    Beep(329.6276 ,500);//e
    Beep(349.2282 ,500);//f
    Beep(391.9954 ,500);//g
    Beep(440.0000 ,500);//a
    Beep(493.8833 ,500);//b
    Beep(523.2511 ,1000);//c
}
void song2 ()
{
    Beep(261.6256 ,900);//c
    Beep(293.6648 ,900);//d
    Beep(329.6276 ,900);//e
    Beep(349.2282 ,900);//f
    Beep(391.9954 ,900);//g
    Beep(440.0000 ,900);//a
    Beep(493.8833 ,900);//b
    Beep(523.2511 ,900);//c
}


void colorfulstring ()
{
    colorful_String( R"(
_____/\\\\\\\\\\______/\\\____________/\\\\\\\\\\\\\___/\\\\\\\\\\\\\\\
 ___/\\\////////\\\___\/\\\___________\/\\\/////////___\/\\\///////////_
  __/\\\_______\/\\\___\/\\\___________\/\\\____________\/\\\___________
   _\/\\\_______\/\\\___\/\\\___________\/\\\____________\/\\\___________
    _\/\\\_______\/\\\___\/\\\___________\/\\\\\\\\\\\\___\/\\\___/\\\\\\\\
     _\/\\\_______\/\\\___\/\\\___________\/\\\/////////___\/\\\__\//////\\\
      _\/\\\_______\/\\\___\/\\\___________\/\\\____________\/\\\_______\/\\\
       _\/\\\\\\\\\\\\\/____\/\\\\\\\\\\\\__\/\\\\\\\\\\\\___\/\\\\\\\\\\\\\/
        __\////////////______\////////////___\////////////_____\////////////    Productions inc. 
)" );

}
int DisplayResourceNAMessageBox()
{

    const int msgboxID = MessageBox(
        NULL,
        (LPCTSTR) "Are you sure?",
        (LPCTSTR) "Title",
        MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
    );
   
    switch (msgboxID)
    {
    case IDCANCEL:
        // TODO: add code
        break;
    case IDTRYAGAIN:
        // TODO: add code
        break;
    case IDCONTINUE:
        // TODO: add code
        break;
    }

    return msgboxID;
}
string input ( int player )
{
    string user_input ;

    if ( player % 2 == 0) 
    {
        cout <<"\nPlayer 2, please enter a letter (A-P) :";
        getline(cin, user_input);
    }
    else
    {
        cout <<"\nPlayer 1, please enter a letter (A-P) :";
        getline(cin, user_input);
    }

    return user_input;
}
void update ( string players_Choice , int player, string game_Board [ ] ) 
{
    int number;


    if ( player % 2 == 0) 
    {
        number = string_To_Number ( players_Choice ) ;
        
        game_Board [ number - 1 ] = "[+] " ; 
    }
    else
    {
        number = string_To_Number ( players_Choice ) ;
        game_Board [ number - 1 ] = "[-] " ;
    }
}
int string_To_Number (string choice)
{
    char character = 'A' ;

    for (int number = 1 ; number <= 26 ; number ++ )
    {
        if ( choice [ 0 ] == tolower ( character ) || choice [ 0 ] == toupper ( character ) )
        {
            return number ;
        }
        character = character + 1 ;
    }
}
void colorful_String (string original)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    string colorful;
    int random;

    /* initialize random seed: */
    srand (time(NULL));

    for ( int i =0 ; i < original.length() ;i++)
    {
        random = rand ( ) % 10 + 1 ; // generate random number between 1 and 10:
        SetConsoleTextAttribute ( hConsole , random ) ; // # Sets color of text to Red

        cout<< original[i];
    }

}
void output ( string game_Board [ ],string choice ) 
{
    if ( choice == "print" )
    {
        for ( int i = 0 ; i < 16 ; i ++ ) 
        {
            colorful_String (game_Board [ i ]) ; 
            if ( ( i + 1) % 4 == 0 ) 
            {
                cout << endl ;
            }
        }
    }
}
void check_Winner ( string game_Board [ ] ) 
{
    //Something needs to go here

}
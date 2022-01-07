#include "MenuPrincipale.h"

#ifndef _WIN32
#define CLEAR "clear"
#endif

MenuPrincipale::MenuPrincipale() {}

MenuPrincipale::~MenuPrincipale()
{
  vector<Menu *>::const_iterator i;
  for (i = Menus.begin(); i != Menus.end(); i++)
    delete (*i);
}

void MenuPrincipale::Draw() const
{
#ifdef _WIN32
  SelectWindows();
#else
  SelectOthers();
#endif
}

void MenuPrincipale::PrintVoci(unsigned int pos) const
{
#ifdef _WIN32
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "Selezionare la configurazione usando le frecce" << endl;
  for (unsigned int d = 0; d < Menus.size(); d++)
  {
    if (d == pos)
    {
      SetConsoleTextAttribute(h, 10);
      cout << "--> ";
      Menus[d]->DrawVoci();
      SetConsoleTextAttribute(h, 15);
      cout << endl;
    }
    else
      Menus[d]->DrawVoci();
    cout << endl;
  }
#else
  cout << "Selezionare la configurazione usando le frecce" << endl;
  for (unsigned int d = 0; d < Menus.size(); d++)
  {
    if (d == pos)
    {
      cout << "\033[32m"
           << "--> ";
      Menus[d]->DrawVoci();
      cout << "\033[0m" << endl;
    }
    else
      Menus[d]->DrawVoci();
    cout << endl;
  }
#endif
}

void MenuPrincipale::SelectWindows() const
{
#ifdef _WIN32
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80

  int c, ex;
  unsigned int pos=0;
  cout << "Selezionare la configurazione usando le frecce" << endl;

  
  do
  {
    system("cls");
    PrintVoci(pos);
    do
    {

      c = getch();
      if (c == 0 || c == 224)
      {
        switch (ex = getch())
        {
        case KEY_UP /* H */:
          //cout << endl << "Up" << endl;//key up
          if (pos != 0)
            pos--;
          break;
        case KEY_DOWN /* K */:
          //cout << endl << "Down" << endl;   // key down
          if (pos < Menus.size() - 1)
            pos++;
          break;

        default:
          break;
        }
        system("cls");
        if (c != 13)
          PrintVoci(pos);
      }
    } while (c != 13);
    /*HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);*/

  cout << "Fine" << endl;

    if (pos != Menus.size() - 1)
      Menus[pos]->Draw();

    /* switch (pos)
    {
    case 0:
      menuplay.Draw();
      break;
    case 2:

      menuoption.Draw();
      break;
      case 0:
                    cout << endl << "Up" << endl;//key up
                		if(pos!=0)
                      	pos--;
                    break;
    case 0:
                    cout << endl << "Up" << endl;//key up
                		if(pos!=0)
                      	pos--;
                    break;

    default:
      break;*/
  } while (pos != Menus.size() - 1);
#endif
}

void MenuPrincipale::SelectOthers() const
{
#ifndef _WIN32
#include <iostream>
#define KEY_UP 65
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_DOWN 66

  // Black magic to prevent Linux from buffering keystrokes.
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~ICANON;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);

  // Once the buffering is turned off, the rest is simple.
  /*cout << "Enter a character: ";
  char c, d, e;
  cin >> c;
  cin >> d;
  cin >> e;
  cout << "\nYour character was ";
  cout << "Enter a character: ";
  //c = cin.get();
  cout << "Your character was " << c << endl;
  // Using 3 char type, Cause up down right left consist with 3 character
  if ((c == 27) && (d = 91))
  {
    if (e == KEY_UP)
    {
      cout << "UP";
    }
    if (e == KEY_DOWN)
    {
      cout << "DOWN";
    }
    if (e == KEY_RIGHT)
    {
      cout << "RIGHT";
    }
    if (e == KEY_LEFT)
    {
      cout << "LEFT";
    }
  }*/

  unsigned int pos = 0;
  cout << "Selezionare la configurazione usando le frecce; premere il tasto a per selezionare" << endl;

  PrintVoci(0);
  system("clear");
  do
  {
    PrintVoci(pos);
    char c, d, e;
    do
    {

      cin >> c;
      if (c != 'a')
      {
        cin >> d;
        cin >> e;
        if ((c == 27) && (d = 91))
        {
          switch (e)
          {
          case KEY_UP /* H */:
            //cout << endl << "Up" << endl;//key up
            if (pos != 0)
              pos--;
            break;
          case KEY_DOWN /* K */:
            //cout << endl << "Down" << endl;   // key down
            if (pos < Menus.size() - 1)
              pos++;
            break;

          default:
            break;
          }
        }
        system("clear");
        if (c != 'a')
          PrintVoci(pos);
      }
    } while (c != 'a');
    /*HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);*/
    system(CLEAR);
    if (pos != Menus.size() - 1)
    {
      Menus[pos]->Draw();
      system(CLEAR);
    }

    /* switch (pos)
    {
    case 0:
      menuplay.Draw();
      break;
    case 2:

      menuoption.Draw();
      break;
      case 0:
                    cout << endl << "Up" << endl;//key up
                		if(pos!=0)
                      	pos--;
                    break;
    case 0:
                    cout << endl << "Up" << endl;//key up
                		if(pos!=0)
                      	pos--;
                    break;

    default:
      break;*/
  } while (pos != Menus.size() - 1);
#endif
}


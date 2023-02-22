#include <iostream>
#include <windows.h>
using namespace std;
void header();
void mainMenu();
void gameStart();
void options();
void printMaze();
void printTruffle();
void printJack();
void printCasper();
void printShifu();
void printCrow();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);

int choice;
string jackDirection = "Up";
string casperDirection = "Left";
string shifuDirection = "Up";
string crowDirection = "Left";

// Character
int truffleX = 6;
int truffleY = 6;

char truffle1[6] = {' ', '/', '|', '_', '/', '|'};
char truffle2[7] = {'(', ' ', 'o', '.', 'o', ' ', ')'};
char truffle3[6] = {' ', '>', ' ', '^', ' ', '<'};

// Enemy1 = Jack (one of the rats) Color = Pink
int jackX = 56;
int jackY = 30;

char jack1[4] = {'(', 'o', 'o', ')'};
char jack2[3] = {' ', '|', '/'};

// Enemy2 = Casper (one of the rats) Color = Blue
int casperX = 100;
int casperY = 17;

char casper1[4] = {'(', 'o', 'o', ')'};
char casper2[3] = {' ', '|', '/'};

// Enemy3 = Shifu (one of the rats) Color = Green
int shifuX = 24;
int shifuY = 30;

char shifu1[4] = {'(', 'o', 'o', ')'};
char shifu2[3] = {' ', '|', '/'};

// Enemy4 = Crow (a bird to which truffle is allergic)
int crowX = 60;
int crowY = 30;

char crow[4] = {'W', '_', '_', 'W'};

void moveTruffleLeft();
void moveTruffleRight();
void moveTruffleUp();
void moveTruffleDown();
void moveJack();
void moveCasper();
void moveShifu();
void moveCrow();

void eraseTruffle();
void eraseJack();
void eraseCasper();
void eraseShifu();
void eraseCrow();

int truffleHealth = 100;
int jackHealth = 100;
int casperHealth = 100;
int shifuHealth = 100;
int crowHealth = 100;

void printJackHealth();
void printCasperHealth();
void printShifuHealth();
void printCrowHealth();
void printTruffleHealth();

void eraseJackHealth();
void eraseCasperHealth();
void eraseShifuHealth();
void eraseCrowHealth();
void eraseTruffleHealth();

int score = 0; // initializing the score to be 0 to avoid garbage value.

void addScore();
void printScore();

int bulletX[1000];
int bulletY[1000];                     // initializing bullet arrays for both quardinates for truffle
bool isBulletActive[1000];
int bulletCount = 0;

int jackBulletX[1000];
int jackBulletY[1000];                // initializing bullet arrays for both quardinates for Jack
bool isJackBulletActive[1000];
int jackBulletCount = 0;

int casperBulletX[1000];
int casperBulletY[1000];               // initializing bullet arrays for both quardinates for Casper
bool isCasperBulletActive[1000];
int casperBulletCount = 0;

int shifuBulletX[1000];
int shifuBulletY[1000];                // initializing bullet arrays for both quardinates for Shifu
bool isShifuBulletActive[1000];
int shifuBulletCount = 0;

void moveBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int index);
void generateBullet();
void bulletCollisionWithJack();
void bulletCollisionWithCasper();
void bulletCollisionWithShifu();

void moveJackBullet();
void printJackBullet(int x, int y);
void eraseJackBullet(int x, int y);
void makeJackBulletInactive(int index);
void generateJackBullet();
void bulletCollisionWithTruffleByJack();

void moveCasperBullet();
void printCasperBullet(int x, int y);
void eraseCasperBullet(int x, int y);
void makeCasperBulletInactive(int index);
void generateCasperBullet();
void bulletCollisionWithTruffleByCasper();

void moveShifuBullet();
void printShifuBullet(int x, int y);
void eraseShifuBullet(int x, int y);
void makeShifuBulletInactive(int index);
void generateShifuBullet();
void bulletCollisionWithTruffleByShifu();


main()
{
    int timer = 0;                         // initializing the timer to be 0;
    header();
    mainMenu();
    gotoxy(0, 40);                         // this is used to move the cursor outside our maze

    while (true)
    {
        if (jackHealth <= 0)               // Jack will be removed if its health is less than or equal to 0.
        {
            eraseJack();
            break;
        }
        if (casperHealth <= 0)             // Casper will be removed if its health is less than or equal to 0.
        {
            eraseCasper();
            break;
        }
        if (shifuHealth <= 0)              // Shifu will be removed if its health is less than or equal to 0.
        {
            eraseShifu();
            break;
        }
        if (crowHealth <= 0)               // Crow will be removed if its health is less than or equal to 0.
        {
            eraseCrow();
            break;
        }
        if (truffleHealth <= 0)            // Truffle will be removed if its health is less than or equal to 0.
        {
            eraseTruffle();
            break;
        }


        if (GetAsyncKeyState(VK_LEFT))       // Pressing the left key will move Truffle to Left.
        {
            moveTruffleLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))      // Pressing the right key will move Truffle to Right.
        {
            moveTruffleRight();
        }
        if (GetAsyncKeyState(VK_UP))         // Pressing the up key will move Truffle Up.
        {
            moveTruffleUp();
        }
        if (GetAsyncKeyState(VK_DOWN))       // Pressing the down key will move Truffle Down.
        {
            moveTruffleDown();
        }
        if (GetAsyncKeyState(VK_SPACE))      // Pressing spacebar will generate the bullet.
        {
            generateBullet();
        }
        if (timer == 3 && (jackHealth > 0))
        {
            moveJack();
        }
        if (timer == 3 && (casperHealth > 0))
        {
            moveCasper();
        }
        if (timer == 3 && (shifuHealth > 0))
        {
            moveShifu();
        }
        if (timer == 3 && (crowHealth > 0))
        {
            moveCrow();
            timer = 0;
        }

        printScore();
        printJackHealth();
        printCasperHealth();
        printShifuHealth();
        printCrowHealth();
        printTruffleHealth();

        moveBullet();

        moveJackBullet();
        bulletCollisionWithJack();
        bulletCollisionWithTruffleByJack();

        moveCasperBullet();
        bulletCollisionWithCasper();
        bulletCollisionWithTruffleByCasper();

        moveShifuBullet();
        bulletCollisionWithShifu();
        bulletCollisionWithTruffleByShifu();

        timer++;
        Sleep(90);
    }
}
void printTruffle()
{
    gotoxy(truffleX, truffleY);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);            // This is used to give Orange color to truffle

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
    for (int i = 0; i < 7; i++)
    {
        cout << truffle1[i];
    }
    gotoxy(truffleX, truffleY + 1);
    for (int i = 0; i < 7; i++)
    {
        cout << truffle2[i];
    }
    gotoxy(truffleX, truffleY + 2);
    for (int i = 0; i < 7; i++)
    {
        cout << truffle3[i];
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void printJack()
{
    gotoxy(jackX, jackY);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);               // This is used to give Pink color to Jack

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    for (int i = 0; i < 4; i++)
    {
        cout << jack1[i];
    }
    gotoxy(jackX, jackY + 1);
    for (int i = 0; i < 4; i++)
    {
        cout << jack2[i];
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void printCasper()
{

    gotoxy(casperX, casperY);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);               // This is used to give Blue color to Casper

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    for (int i = 0; i < 4; i++)
    {
        cout << casper1[i];
    }
    gotoxy(casperX, casperY + 1);
    for (int i = 0; i < 4; i++)
    {
        cout << casper2[i];
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void printShifu()
{
    gotoxy(shifuX, shifuY);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                 // This is used to give Green color to Shifu

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int i = 0; i < 4; i++)
    {
        cout << shifu1[i];
    }
    gotoxy(shifuX, shifuY + 1);
    for (int i = 0; i < 4; i++)
    {
        cout << shifu2[i];
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void printCrow()
{
    gotoxy(crowX, crowY);

    for (int i = 0; i < 4; i++)
    {
        cout << crow[i];
    }
}

void moveTruffleLeft()
{
    char next1 = getCharAtxy(truffleX - 1, truffleY);
    char next2 = getCharAtxy(truffleX - 1, truffleY + 1);
    char next3 = getCharAtxy(truffleX - 1, truffleY + 2);

    if ((next1 == ' ' || next1 == '.'|| next1 == '+' || next1 == '$') && (next2 == ' ' || next2 == '.'|| next2 == '+' || next2 == '$') && (next3 == ' ' || next3 == '.' || next3 == '+' || next3 == '$'))
    {
        if (next1 == '.' || next2 == '.' || next3 == '.')
        {
            score += 1;                                                 // By eating the cat food, score will be increased to 1 
        }
         if (next1 == '+' || next2 == '+' || next3 == '+')
        {
            truffleHealth--;                                            // By getting hit by a bullet Truffle's health will be decreased to 1
        }
        if (next1 == '$' || next2 == '$' || next3 == '$')
        {
            score += 5;                                                  // By eating the fish, score will be increased to 5
        }
        {
            eraseTruffle();
            truffleX--;
            printTruffle();
        }
    }
}

void moveTruffleRight()
{
    char next1 = getCharAtxy(truffleX + 7, truffleY);
    char next2 = getCharAtxy(truffleX + 8, truffleY + 1);
    char next3 = getCharAtxy(truffleX + 8, truffleY + 2);

    if ((next1 == ' ' || next1 == '.' || next1 == '+' || next1 == '$' ) && (next2 == ' ' || next2 == '.'|| next2 == '+' || next2 == '$') && (next3 == ' ' || next3 == '.' || next3 == '+' || next3 == '$'))
    {
        if (next1 == '.' || next2 == '.' || next3 == '.')
        {
            score += 1;                                                   // By eating the cat food, score will be increased to 1
        }
        if (next1 == '+' || next2 == '+' || next3 == '+')
        {
            truffleHealth--;                                              // By getting hit by a bullet Truffle's health will be decreased to 1
        }
        if (next1 == '$' || next2 == '$' || next3 == '$')
        {
            score += 5;                                                    // By eating the fish, score will be increased to 5
        }
        eraseTruffle();
        truffleX++;
        printTruffle();
    }
}
void moveTruffleUp()
{
    char next1 = getCharAtxy(truffleX, truffleY - 1);
    char next2 = getCharAtxy(truffleX + 1, truffleY - 2);
    char next3 = getCharAtxy(truffleX + 2, truffleY - 2);
    char next4 = getCharAtxy(truffleX + 3, truffleY - 2);
    char next5 = getCharAtxy(truffleX + 4, truffleY - 2);
    char next6 = getCharAtxy(truffleX + 5, truffleY - 2);
    char next7 = getCharAtxy(truffleX + 6, truffleY - 2);

    if ((next1 == ' ' || next1 == '.' || next1 == '+' || next1 == '$') && (next2 == ' ' || next2 == '.'|| next2 == '+' || next2 == '$') && (next3 == ' ' || next3 == '.'|| next3 == '+' || next3 == '$') && (next4 == ' ' || next4 == '.'|| next4 == '+' || next4 == '$') && (next5 == ' ' || next5 == '.' || next5 == '+' || next5 == '$') && (next6 == ' ' || next6 == '.' || next6 == '+' || next6 == '$') && (next7 == ' ' || next7 == '.' || next7 == '+' || next7 == '$'))
    {
        if (next1 == '.' || next2 == '.' || next3 == '.' || next4 == '.' || next5 == '.' || next6 == '.' || next7 == '.')
        {
            score += 1;                             // By eating the cat food, score will be increased to 1
        }
        if (next1 == '+' || next2 == '+' || next3 == '+' || next4 == '+' || next5 == '+' || next6 == '+' || next7 == '+')
        {
            truffleHealth--;                       // By getting hit by a bullet Truffle's health will be decreased to 1
        }
        if (next1 == '$' || next2 == '$' || next3 == '$' || next4 == '$' || next5 == '$' || next6 == '$' || next7 == '$')
        {
            score += 5;                            // By eating the fish, score will be increased to 5
        }
        eraseTruffle();
        truffleY--;
        printTruffle();
    }
}
void moveTruffleDown()
{
    char next1 = getCharAtxy(truffleX, truffleY + 3);
    char next2 = getCharAtxy(truffleX + 1, truffleY + 3);
    char next3 = getCharAtxy(truffleX + 2, truffleY + 4);
    char next4 = getCharAtxy(truffleX + 3, truffleY + 4);
    char next5 = getCharAtxy(truffleX + 4, truffleY + 4);
    char next6 = getCharAtxy(truffleX + 5, truffleY + 4);
    char next7 = getCharAtxy(truffleX + 6, truffleY + 4);
    if ((next1 == ' ' || next1 == '.' || next1 == '+' || next1 == '$') && (next2 == ' ' || next2 == '.'|| next2 == '+' || next2 == '$') && (next3 == ' ' || next3 == '.'|| next3 == '+'|| next3 == '$') && (next4 == ' ' || next4 == '.'|| next4 == '+' || next4 == '$') && (next5 == ' ' || next5 == '.'|| next5 == '+'|| next5 == '$') && (next6 == ' ' || next6 == '.' || next6 == '+' || next6 == '$') && (next7 == ' ' || next7 == '.' || next7 == '+' || next7 == '$'))
    {
        if (next1 == '.' || next2 == '.' || next3 == '.' || next4 == '.' || next5 == '.' || next6 == '.' || next7 == '.')
        {
            score += 1;                           // By eating the cat food, score will be increased to 1
        }
        if (next1 == '+' || next2 == '+' || next3 == '+' || next4 == '+' || next5 == '+' || next6 == '+' || next7 == '+')
        {
            truffleHealth--;                      // By getting hit by a bullet Truffle's health will be decreased to 1
        }
        if (next1 == '$' || next2 == '$' || next3 == '$' || next4 == '$' || next5 == '$' || next6 == '$' || next7 == '$')
        {
            score += 5;                           // By eating the fish, score will be increased to 5
        }
        eraseTruffle();
        truffleY++;
        printTruffle();
    }
}

void eraseTruffle()                        // Function to remove truffle
{
    gotoxy(truffleX, truffleY);
    for (int i = 0; i < 7; i++)
    {
        cout << " ";
    }
    gotoxy(truffleX, truffleY + 1);
    for (int i = 0; i < 7; i++)
    {
        cout << " ";
    }
    gotoxy(truffleX, truffleY + 2);
    for (int i = 0; i < 7; i++)
    {
        cout << " ";
    }
}
void eraseJack()                           // Function to remove Jack
{
    gotoxy(jackX, jackY);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
    gotoxy(jackX, jackY + 1);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
}
void moveJack()                           // Function to move Jack
{
    generateJackBullet();
    if (jackDirection == "Up")
    {
        char next = getCharAtxy(jackX, jackY - 1);
        if (next == ' ')
        {
            eraseJack();
            jackY--;
            printJack();
        }
        else if (next == '#')
        {
            jackDirection = "Down";
        }
    }

    if (jackDirection == "Down")
    {
        char next = getCharAtxy(jackX, jackY + 4);
        if (next == ' ')
        {
            eraseJack();
            jackY++;
            printJack();
        }
        else if (next == '#')
        {
            jackDirection = "Up";
        }
    }
}
void eraseJackHealth()                           // Function to remove Jack Health
{
    gotoxy(131, 15);
    cout << "                                               ";
}
void printJackHealth()
{
    if (jackHealth >= 0)
    {
        gotoxy(131, 15);
        cout << "Jack Health: " << jackHealth;
    }
}
void eraseCasper()                               // Function to remove Casper
{
    gotoxy(casperX, casperY);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
    gotoxy(casperX, casperY + 1);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
}
void moveCasper()                                 // Function to move Casper
{
    generateCasperBullet();
    if (casperDirection == "Right")
    {
        char next = getCharAtxy(casperX - 1, casperY);
        if (next == ' ')
        {
            eraseCasper();
            casperX--;
            printCasper();
        }
        else if ((next == '#') || (next == '.'))
        {
            casperDirection = "Left";
        }
    }

    if (casperDirection == "Left")
    {
        char next = getCharAtxy(casperX + 4, casperY);
        if (next == ' ')
        {
            eraseCasper();
            casperX++;
            printCasper();
        }
        else if ((next == '#') || (next == '.'))
        {
            casperDirection = "Right";
        }
    }
}
void eraseCasperHealth()                        // Function to remove Casper Health
{
    gotoxy(131, 16);
    cout << "                                               ";
}
void printCasperHealth()
{
    if (casperHealth >= 0)
    {
        gotoxy(131, 16);
        cout << "Casper Health: " << casperHealth;
    }
}

void eraseShifu()                               // Function to remove Shifu
{
    gotoxy(shifuX, shifuY);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
    gotoxy(shifuX, shifuY + 1);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
}
void moveShifu()                               // Function to move Shifu
{
    generateShifuBullet();
    if (shifuDirection == "Up")
    {
        char next = getCharAtxy(shifuX, shifuY - 1);
        if (next == ' ')
        {
            eraseShifu();
            shifuY--;
            printShifu();
        }
        else if (next == '#')
        {
            shifuDirection = "Down";
        }
    }

    if (shifuDirection == "Down")
    {
        char next = getCharAtxy(shifuX, shifuY + 4);
        if (next == ' ')
        {
            eraseShifu();
            shifuY++;
            printShifu();
        }
        else if (next == '#')
        {
            shifuDirection = "Up";
        }
    }
}
void eraseShifuHealth()                       // Function to remove Shifu Health
{
    gotoxy(131, 17);
    cout << "                                               ";
}
void printShifuHealth()
{
    if (shifuHealth >= 0)
    {
        gotoxy(131, 17);
        cout << "Shifu Health: " << shifuHealth;
    }
}
void eraseCrow()                              // Function to remove crow
{
    gotoxy(crowX, crowY);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
}
void moveCrow()                              // Function to move crow
{
    if (crowDirection == "Right")
    {
        char next = getCharAtxy(crowX - 1, crowY);
        if (next == ' ')
        {
            eraseCrow();
            crowX--;
            printCrow();
        }
        else if ((next == '#') || (next == '.'))
        {
            crowDirection = "Left";
        }
    }

    if (crowDirection == "Left")
    {
        char next = getCharAtxy(crowX + 4, crowY);
        if (next == ' ')
        {
            eraseCrow();
            crowX++;
            printCrow();
        }
        else if ((next == '#') || (next == '.'))
        {
            crowDirection = "Right";
        }
    }
}
void eraseCrowHealth()                      // Function to remove Crow Health
{
    gotoxy(131, 18);
    cout << "                                               ";
}
void printCrowHealth()                      // Function to print Crow Health
{
    if (crowHealth >= 0)
    {
        gotoxy(131, 18);
        cout << "Crow Health: " << crowHealth;
    }
}
void printTruffleHealth()                   // Function to print Truffle Health
{
    if (truffleHealth >= 0)
    {
        gotoxy(130, 10);
        cout << "Truffle Health: " << truffleHealth;
    }
}

void eraseTruffleHealth()                   // Function to erase Truffle Health
{
    gotoxy(131, 10);
    cout << "                  ";
}

void generateBullet()                       // Function to generate Truffle's Bullet
{
    bulletX[bulletCount] = truffleX + 7;
    bulletY[bulletCount] = truffleY;
    isBulletActive[bulletCount] = true;
    gotoxy(truffleX + 7, truffleY);
    cout << "*";
    bulletCount++;
}
void printBullet(int x, int y)               // Function to print Truffle's Bullet
{
    gotoxy(x, y);
    cout << "*";
}

void eraseBullet(int x, int y)               // Function to erase Truffle's Bullet
{
    gotoxy(x, y);
    cout << " ";
}

void makeBulletInactive(int index)           // Function to make Truffle's Bullet Inactive
{
    isBulletActive[index] = false;
}

void moveBullet()                            // Function to move Truffle's Bullet
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i] == true)
        {
            char next = getCharAtxy(bulletX[i] + 1, bulletY[i]);
            if (next != ' ' && next != '#')
            {
                eraseBullet(bulletX[i], bulletY[i]);
                makeBulletInactive(i);
                score++;
            }
            else if(next == '#')
            {
                eraseBullet(bulletX[i], bulletY[i]);
                makeBulletInactive(i);
            }
        
            else
            {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletX[i]++;
                printBullet(bulletX[i], bulletY[i]);
            }
        }
    }
}
void bulletCollisionWithJack()                     // If bullet collides Jack
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i])
        {
            if (bulletX[i] + 1 == jackX && (bulletY[i] == jackY || bulletY[i] == jackY + 2))
            {
                addScore();
                eraseJackHealth();
                jackHealth = jackHealth - 1;
            }
            if (jackX - 1 == bulletX[i] && jackY + 1 == bulletY[i])
            {
                addScore();
                eraseJackHealth();
                jackHealth = jackHealth - 1;
            }
        }
    }
}

void moveJackBullet()                     // Function to move Jack's Bullet
{
    for (int i = 0; i < jackBulletCount; i++)
    {
        if (isJackBulletActive[i] == true)
        {
            char next = getCharAtxy(jackBulletX[i] - 1, jackBulletY[i]);
            if (next != ' ')
            {
                eraseJackBullet(jackBulletX[i], jackBulletY[i]);
                makeJackBulletInactive(i);
            }
            else
            {
                eraseJackBullet(jackBulletX[i], jackBulletY[i]);
                jackBulletX[i]--;
                printJackBullet(jackBulletX[i], jackBulletY[i]);
            }
        }
    }
}
void generateJackBullet()                           // Function to generate Jack's Bullet
{
    jackBulletX[jackBulletCount] = jackX - 1;
    jackBulletY[jackBulletCount] = jackY + 1;
    isJackBulletActive[jackBulletCount] = true;
    gotoxy(jackBulletX[jackBulletCount], jackBulletY[jackBulletCount]);
    cout << "+";
    jackBulletCount++;
}
void printJackBullet(int x, int y)                 // Function to print Jack's Bullet
{
    gotoxy(x, y);
    cout << "+";
}

void eraseJackBullet(int x, int y)                  // Function to erase Jack's Bullet
{
    gotoxy(x, y);
    cout << " ";
}

void makeJackBulletInactive(int index)              // Function to make Jack's Bullet Inactive
{
    isJackBulletActive[index] = false;
}

void bulletCollisionWithTruffleByJack()             // If Jack hits truffle a Bomb
{
    for (int i = 0; i < jackBulletCount; i++)
    {
        if (isJackBulletActive[i])
        {
            if (jackBulletX[i] - 1 == truffleX + 3 && (jackBulletY[i] == truffleY || jackBulletY[i] == truffleY + 1 || jackBulletY[i] == truffleY + 2))
            {
                eraseTruffleHealth();
                truffleHealth = truffleHealth - 1;
            }
        }
    }
}

void bulletCollisionWithCasper()                         // If bullet collides Casper
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i])
        {
            if (bulletX[i] + 1 == casperX && (bulletY[i] == casperY || bulletY[i] == casperY + 2))
            {
                addScore();
                eraseCasperHealth();
                casperHealth = casperHealth - 1;
            }
            if (casperX - 1 == bulletX[i] && casperY + 1 == bulletY[i])
            {
                addScore();
                eraseCasperHealth();
                casperHealth = casperHealth - 1;
            }
        }
    }
}

void moveCasperBullet()                       // Function to move Casper's Bullet
{
    for (int i = 0; i < casperBulletCount; i++)
    {
        if (isCasperBulletActive[i] == true)
        {
            char next = getCharAtxy(casperBulletX[i] - 1, casperBulletY[i]);
            if (next != ' ')
            {
                eraseCasperBullet(casperBulletX[i], casperBulletY[i]);
                makeCasperBulletInactive(i);
            }
            else
            {
                eraseCasperBullet(casperBulletX[i], casperBulletY[i]);
                casperBulletX[i]--;
                printCasperBullet(casperBulletX[i], casperBulletY[i]);
            }
        }
    }
}
void generateCasperBullet()                   // Function to generate Casper's Bullet
{
    casperBulletX[casperBulletCount] = casperX - 7;
    casperBulletY[casperBulletCount] = casperY + 1;
    isCasperBulletActive[casperBulletCount] = true;
    gotoxy(casperBulletX[casperBulletCount], casperBulletY[casperBulletCount]);
    cout << "+";
    casperBulletCount++;
}
void printCasperBullet(int x, int y)           // Function to print Casper's Bullet
{
    gotoxy(x, y);
    cout << "+";
}

void eraseCasperBullet(int x, int y)           // Function to erase Casper's Bullet
{
    gotoxy(x, y);
    cout << " ";
}

void makeCasperBulletInactive(int index)        // Function to make Casper's Bullet Inactive
{
    isCasperBulletActive[index] = false;
}

void bulletCollisionWithTruffleByCasper()        // If Casper hits truffle a Bomb
{
    for (int i = 0; i < casperBulletCount; i++)
    {
        if (isCasperBulletActive[i])
        {
            if (casperBulletX[i] - 1 == truffleX + 3 && (casperBulletY[i] == truffleY || casperBulletY[i] == truffleY + 1 || casperBulletY[i] == truffleY + 2))
            {
                eraseTruffleHealth();
                truffleHealth = truffleHealth - 1;
            }
        }
    }
}

void bulletCollisionWithShifu()                  // If bullet collides Shifu
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i])
        {
            if (bulletX[i] + 1 == shifuX && (bulletY[i] == shifuY || bulletY[i] == shifuY + 2))
            {
                addScore();
                eraseShifuHealth();
                shifuHealth = shifuHealth - 1;
            }
            if (shifuX - 1 == bulletX[i] && shifuY + 1 == bulletY[i])
            {
                addScore();
                eraseShifuHealth();
                shifuHealth = shifuHealth - 1;
            }
        }
    }
}

void moveShifuBullet()                              // Function to move Shifu's Bullet
{
    for (int i = 0; i < shifuBulletCount; i++)
    {
        if (isShifuBulletActive[i] == true)
        {
            char next = getCharAtxy(shifuBulletX[i] - 1, shifuBulletY[i]);
            if (next != ' ')
            {
                eraseShifuBullet(shifuBulletX[i], shifuBulletY[i]);
                makeShifuBulletInactive(i);
            }
            else
            {
                eraseShifuBullet(shifuBulletX[i], shifuBulletY[i]);
                shifuBulletX[i]--;
                printShifuBullet(shifuBulletX[i], shifuBulletY[i]);
            }
        }
    }
}
void generateShifuBullet()                        // Function to generate shifu's Bullet
{
    shifuBulletX[shifuBulletCount] = shifuX - 7;
    shifuBulletY[shifuBulletCount] = shifuY + 1;
    isShifuBulletActive[shifuBulletCount] = true;
    gotoxy(shifuBulletX[shifuBulletCount], shifuBulletY[shifuBulletCount]);
    cout << "+";
    shifuBulletCount++;
}
void printShifuBullet(int x, int y)                // Function to print Shifu's Bullet
{
    gotoxy(x, y);
    cout << "+";
}

void eraseShifuBullet(int x, int y)                // Function to erase Shifu's Bullet
{
    gotoxy(x, y);
    cout << " ";
}

void makeShifuBulletInactive(int index)            // Function to make Shifu's Bullet Inactive
{
    isShifuBulletActive[index] = false;
}

void bulletCollisionWithTruffleByShifu()            // If Shifu hits truffle a Bomb
{
    for (int i = 0; i < shifuBulletCount; i++)
    {
        if (isShifuBulletActive[i])
        {
            if (shifuBulletX[i] - 1 == truffleX + 3 && (shifuBulletY[i] == truffleY || shifuBulletY[i] == truffleY + 1 || shifuBulletY[i] == truffleY + 2))
            {
                eraseTruffleHealth();
                truffleHealth = truffleHealth - 1;
            }
        }
    }
}
void addScore()             // Function to add the score
{
    score++;
}
void printScore()           // Function to print the score
{
    gotoxy(130, 8);
    cout << "Score: " << score << " ";
}


void gotoxy(int x, int y)     // Gotoxy Function
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void gameStart()             // Function to start the game.
{
    system("cls");
    printMaze();
    printTruffle();
    printJack();
    printCasper();
    printShifu();
    printCrow();
}
void options()             // Function to display the options if user enters (2) as an option
{
    int number;
    system("cls");
    cout << "Press the Right key to move truffle to the Right" << endl;
    cout << "Press the Left key to move truffle to the Left" << endl;
    cout << "Press the Up key to move truffle Up" << endl;
    cout << "Press the Down key to move truffle Down" << endl;
    cout << "If the enemy bomb hits truffle, her score will be decreased to one value." << endl;
    cout << "If truffle's bullet hits the enemy , its score will be decreased to one value." << endl;
    cout << "If truffle hits the crow, her score will be decreased to one value." << endl;
    cout << "When truffle eats the food pellets, her score will be increased to one value." << endl;
    cout << "If truffle eats the fish , her score will be increased to 5." << endl;

    cout << "Press any number to go back........" << endl;
    cin >> number;

    mainMenu();
}
void mainMenu()                 // Function to show the main menu
{
    cout << " ############################################################################################################# " << endl;
    cout << " #                                                                                                           # " << endl;
    cout << " #  _____         ___ ___ _        _____ _          _____                 _                                  # " << endl;
    cout << " # |_   _|___ _ _|  _|  _| |___   |_   _| |_ ___   |_   _|___ ___ _ _ ___| |___ ___                          # " << endl;
    cout << " #   | | |  _| | |  _|  _| | -_|    | | |   | -_|    | | |  _| .'| | | -_| | -_|  _|                         # " << endl;
    cout << " #   |_| |_| |___|_| |_| |_|___|    |_| |_|_|___|    |_| |_| |__,|\\/|___|_|___|_|                           # " << endl;
    cout << " #                                                                                                           # " << endl;
    cout << " #                                                                                                           # " << endl;
    cout << " ############################################################################################################# " << endl;

    cout << "PRESS (1) TO START: " << endl;
    cout << "PRESS (2) FOR OPTIONS: " << endl;
    cout << "PRESS (3) TO EXIT: " << endl;

    cout << "ENTER YOUR CHOICE: " << endl;
    cin >> choice;
    if (choice == 1)
    {
        gameStart();
    }
    if (choice == 2)
    {
        options();
    }
    if (choice == 3)
    {
        cout << "GAME ENDED" << endl;
        header();
    }
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void header()            // Function to display the header
{
    cout << "                                                                                                                                                       " << endl;
    cout << "                                                                                                                                                       " << endl;
    cout << "              #######      #**#!!###                                                                                                                   " << endl;
    cout << "              #**#!!!!##   #****#!!!!#                                                                                                                 " << endl;
    cout << "              #****###!!!#  #*****#!!!!#                                                                                                               " << endl;
    cout << "              #*******#!!!# #******#!!!!#                                                                                                              " << endl;
    cout << "              #*********#!###!*!*!*#!!!!!#        --                                                                                                   " << endl;
    cout << "              #!*!*!*!*!*!#!##########!!!!#      /_                                                                                                    " << endl;
    cout << "              ###########!##!!!!!!!!!!#!!!#     //__                                                                                                   " << endl;
    cout << "           ###!!!!!!!!!!!#!!!!!!!!!!!!!#!!!#                                                                                                           " << endl;
    cout << "_     ##!!#!!!!!!!!!!!#!!!!!!!!!!!######!!!!!!!*#                                                                                                      " << endl;
    cout << " \\  ##!!#!!!!!!!!!!!!#!!!!#######     #!!!!!!***#                                                                                                     " << endl;
    cout << " ___\\#!!!###################*****       #...!!*****#                                                                                                  " << endl;
    cout << "/   \\#!!!.#       ***** #     ***        #....*******#                                                                                                " << endl;
    cout << "    #*....#        ***   #              #.......*****#                                                                                                 " << endl;
    cout << "   #**.....##          *****          ##........!!****#                                                                                                " << endl;
    cout << "  #!........##       *******#########......#...!!!!!*#                                                                                                 " << endl;
    cout << " #!...........#######.*****...............#.#..!!!!**#                                                          .---.                                  " << endl;
    cout << " #*.....##.............#..#...............#...#.!!****#                                                         |   |      __.....__                   " << endl;
    cout << " #*....#.#............#....#............##......!*****#                                           _.._     _.._ |   |  .-''         '-.                " << endl;
    cout << " #*.......##.......###......###........#.......!!!****#                  .|  .-,.--.            .' .._|  .' .._||   | /     .-'''-.    .               " << endl;
    cout << " #*.........#######......!!....########.......!!!!!***#                .' |_ |  .-. |           | '      | '    |   |/     |________|   |              " << endl;
    cout << " #!!!.................!!!!!!!!.............!!!*******#               .'     || |  | | _    _  __| |__  __| |__  |   ||                  |              " << endl;
    cout << "  #!!!!............!!!!!!!!!!!!!!!!!!!!!!!!!!!******#               '--.  .-'| |  | || '  / ||__   __||__   __| |   ||    .-------------'              " << endl;
    cout << "   #*******!!!!!!!!!!!!!!!!!!!!!!!!!!!!***!!!!*****#                   |  |  | |  '-.' | .' |   | |      | |    |   | |    '-.____...---.              " << endl;
    cout << "     #******!!!!!!!!!!!!!!!!!!!!!!!!!********!!****#                   |  |  | |    /  | /  |   | |      | |    |   |  `.             .'               " << endl;
    cout << "     ##*****!!!!!!!!!!!!!!!!!!!!!#*************###                     |  '.'| |   |   `'.  |   | |      | |    '---'    `''-...... -'                 " << endl;
    cout << "       ##****!!!!!!!!!!!!!!!!!!!!!###******####                        `'-'         `-'  `--'   |_|      |_|                                           " << endl;
    cout << "        ####!!!!!!!!!!!!!!!!!!!!!!!!######!#                                                                                                           " << endl;
}

void printMaze()                // Function to display the maze
{
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    // here # represents the walls
    // . represents the cat food
    // $ represents the fish

    cout << "   ############################################################################################################################ " << endl;
    cout << "   #                               #                                                   #                                      # " << endl;
    cout << "   #                               #                     $               .             #                           .          # " << endl;
    cout << "   #                               #                                                   #                   .                  # " << endl;
    cout << "   #        .           ##########################                       .             #            .                         # " << endl;
    cout << "   #                    #                        #                                     #                .         .           # " << endl;
    cout << "   #           .        #                        #                           .         #                    $ .               # " << endl;
    cout << "   #                    #                        #     .         #                     #                                      # " << endl;
    cout << "   #       .            #                        #               #        .            #############                          # " << endl;
    cout << "   #                    #                        #         .     #                                                            # " << endl;
    cout << "   #             .      #############            #               #                                                            # " << endl;
    cout << "   #                                                  .          #         ...      .....          .....                      # " << endl;
    cout << "   #       .                                                     #                                                            # " << endl;
    cout << "   #                       .                              .      #                                                            # " << endl;
    cout << "   #                               $                             #########################################                    # " << endl;
    cout << "   #######################        .                                   .     ..         .....        ..             .          # " << endl;
    cout << "   #                                                    .                                                                     # " << endl;
    cout << "   #                                                            .                                                             # " << endl;
    cout << "   #                 .                                                                                                        # " << endl;
    cout << "   #                     .                                                                                                    # " << endl;
    cout << "   #                                  ############                      #######################                               # " << endl;
    cout << "   #             .                    #                       .                     #                                         # " << endl;
    cout << "   #                                  #                                             #                            ..           # " << endl;
    cout << "   #                                  #                      $                      #          ..                             # " << endl;
    cout << "   #############                      #                                ..           #                                         # " << endl;
    cout << "   #                                  #                                             #                                         # " << endl;
    cout << "   #                                  ############          .                       #                                         # " << endl;
    cout << "   #                                             #                                                                            # " << endl;
    cout << "   #             ..          .        ...        #                         .                         ########################## " << endl;
    cout << "   #                                             #                                                                            # " << endl;
    cout << "   #     .             ..                      . #                                                                            # " << endl;
    cout << "   #                                             #                         .                                                  # " << endl;
    cout << "   #                                  ############                                                     $                      # " << endl;
    cout << "   #             .$           ..                          ..                                                                  # " << endl;
    cout << "   #                                                            ###########  .       ..                                       # " << endl;
    cout << "   #                                                            #                                     ..                      # " << endl;
    cout << "   #                                                            #                                                             # " << endl;
    cout << "   #                                                            #                                                             # " << endl;
    cout << "   #                                                            #                                                             # " << endl;
    cout << "   ############################################################################################################################ " << endl;
   SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
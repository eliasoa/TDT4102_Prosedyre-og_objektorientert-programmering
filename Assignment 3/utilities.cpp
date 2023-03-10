#include "cannonball_viz.h"
#include "utilities.h"
#include "cannonball.h"
#include "std_lib_facilities.h"

string message = "To shoot the cannonball, guess an angle Theta and a startspeed to shoot the cannonball with.\nTo win you have to get within +- 5 meters of the target.\nYou have 10 attempts";

int randomWithLimits(int lowerBound, int upperBound){
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(lowerBound,upperBound);

    int number = distribution(generator);
    return number;
}

void printBilly(void){
        cout << R"(
##(####((((((((((((((((((((((((##((((###########%&&%################(/*,,,,....,,,,,*/(########%#%%%%###%#%%%#%%#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&%%%%%%&
##########################################%%%####%&%#########*.. .   . ...    ....,,,,********(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&%%&&&%&&%&&&%
########################%%##%#%%%#%%%###%%%%%%%%%%&&%%%(,   .          .. .  .....,,..*,,**,*,,****(%&&&&&&&&&%%&%%%%%%%&%%%%%&%%&&&%&&&&&&&&&&&&&&&&&
###########%%%%#%%%%%%%%%%%%%%%%%%%%%%%%%%%&&&&&%%%%/.              ...  ..      .,,,,,,...,,,,,*******(&&&&&&&&&&&&&&&&&&&&&&&&&&&%&&&&&&&&&&&&&&&&&&
#########%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&&&&&&%%%%(. . ..    .     ....... .....   ,,,,,...,,,,*,**********/%&&@&@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#%%##%%%#%%%%%%%%%%%%%%%%%%%%%%&%&&&&&&&&&&&&&%,. .. .... ........... ........ .........,*******,,**********/(&&&&@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
%%%%%%%%%%%%%%%%%%%%%%%%&%&%%%%&&&&%&&&&&&&&%,.  .        ........,..... ..   .,*//((((((#######(((((/*,,**////#@&&&@@@@@@@@@@@@&&&@&&&&&&&&&&&&&&&&&&
%%%%%%%%%%%%%%%%&&&&&&&&&%%%%&&&&&&@&%%&&&/   ,**/*.,,.,,,*,**////***,,    ,(###%%%%&%%%%%%%%%%%%%%%#####(/////((&&@@&&&&&&&&@@@@@@@@@@@@@@@@@@@@&&@@@
&%%%&%&%&%&&&&&&&&&&&&&&%%&&&&@&%&%%%&&# ..**((((##%%%%%%%#///(##(##////(/(#%%&&&&&&&@@@@@@@@@@&&&&&%&%%%%##((////#&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
&&&&&&&&&&&&%&&&&&&&&&&&&&%&&&&%%%%%&% .*((#%&&&&@@@&&%%&&&&,,*/*((((//((##%%&&&&&@@@@@@@&&&&&&&&&&@&@&&%%#####(/(/#@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@
&&&&&&&&&&&&&&&&&&&&&&&&%%&&&%%#%&&@%,/(#%%&&&@@@%/,((((#&&&%,,.**,..,  ,*((###%%&@@@@@&&&&%%%&@@&&&@@&&&&%%%%%#(/((#@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@
&&&&&&&&&&&&&&&&&&&&&%%#%&&&&%%&&&@@@(#%%%#%%%@@%(..(#%&&&&&%..,,.     ,,/*/((##%&@@@@@@@&&&&@@@@@&&@@&&%%%%%%&%%%##(%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
&&&&&@@@@@@@&&&&&&&&%%&&&&%&&%%&@@@@@*/(**,,%&@&%%#%%%%&&%&%. ..     .,,*///*//(#%@@@@@@@@&&&&&&&&&&@@&%(####%&%%%%%##@@@@@@&@&&@@@@@@@@@@@@@@@@@@@@@@
&@@@@@@@&@@@@@@&&&&@&&&&&&%(#%&@@@@@@%/****/##%&&%%%&&%&#,...    .   .,,*///////(((#&&@@@@&@&&&%#(((///////(((#%%%%%%%#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
&@@@@@@@@@@@@@@&&&&@@&@&&%%#%@@@@@@&&#(##(,,,****,,,,,. .....   .   ..**/(//////(///(/**//**,,*.., ..(,(/(****(%###%%%(%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@&@&&&@@&&&&&%%&&@@@@@@@%/,..*#*.,,..,. ..,,,,,,,. ..    ..,//((((((((/////*************###/**(%%%%&%%(%###%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@&@@@@@&&@@@@@&&&%%&&&@@@&@(  *(/.,(#,,.************,,...     .**//(//((####(((///////,/***#%%%///##%(*/(/(/(####%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@&&@@&@@&&&&&&&&@@@@@@@&((( .((,.*#*,*****//////**,. ,      ,**/////(####(#(((((((((/((((%%%((/(#(**%%(//(%#%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@&@@@&&&&&&@@@@&@&&&((./,./#*,,%%/////((//////*, .    . .,*///(((((#(((((((((((((((#%%&&&#((%%%(&&#((&&%(%##&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@&/(///,*%%*(%%%((((((((((/(**,,    ..***///////((((((((((((((((##((%&&#((%&&##&&#((#&###%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@&&@@@@@@&@@@&@/*,#/,(%%/#&&(((((((((((((/*..   . .**//((((////###(((((#(#(#((#(##&&%/(#&&%##&&@&&&%%&%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@#%%%/*%%/(%&&(#(##########(,,      ,///(((##((///((#############((##&&%##&&&%##%%%%&%@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@%&@&@@@#/*.#%##%@&%#######%%#%#%%%,   ..*/(###%#####((((/####%%#%%%%%%####%&&&%%%&@&@@&@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&%%&((#&&&%####%%#%%%%%&%(,*///(#%%%%%%&%&&&&&&&&%%%%%%%%%%%%%&%%%#%@@@@&&%%&&&&&%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@&@&&&@@@@@@@@&&@@&&@&@&%#####%%%&&&&&&%%%%%######%%%&&&&&&&&&&&&&&&&&&@@&&&&%%&&%&%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@&@@@&@@@#*#%%%%%%%&&&&&&&%%((#/////((%#%&@@@@@@@&&%##%&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@&@@@@@@@@@@@@&@@@@@@@@@@@@@%##(#%(**,*,(%&&%((#%&@&&&&&&&@@@@@@@@@&&@&&&&&&&@&&&&@@@@&&&&@@&&@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
%&&&&&&&&&&&#&@&@@@@@@@@@@&@@@@@@@@@@@@@@%*..,,,, .,.*/(&&%&&&&&&&&&&&@@@@@@@@@@@@@@&@&&&&&&&&&&%%&%%&&@@@&@@&@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
%%%%%%%&&&&&%%%&&&@@@@@@@@@@@@@@@@@@@@&@@&*. .,.,....,*(#%%%(((##%%%%%%%%&&&&&&&&@@@@@&%(##%&/#(###%%%%%%%%%&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
&&&@@@&@&@@@@&&@&&@@@@@@@@@@@@@@@@@@@@@@@&(,,.,,. . .*,/(#&%&&&&&&&&&&&&&&&&&&&&&&&&%&@&%############%%&%%&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@&@@&,,.,..  ..,/((#&//%%#%%%%%%%%%%%&&&&&%%%%%#(@&####(#######%%%&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@&&@@@@@@@@@@@&&&@@@@@@@@@@@@@@@@@&@@@@@&/,,,.....,/((#%%/.***/(((#(#(((//((#(#####%%@%%#########%%%&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&#,....   **/(#%%.,**/(((((/((//////*///*//((@&%#(#%#####%%&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@&&@&@@@@@&&&&&@&&&&&&&(,.   , .*//(##.../((((###*/(/(**,. .,*/////%&%#######%%%%&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@&&@&@@@&&#,... ..,//(##( ,**(((((((/*((((*...,***//((#%%#(#####%%&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&%/**,,*///(((#. ,,/(((((((/((((**...***///((#####%###%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@&@@@@@@@@@@@&&&(////(((((#(.,,*///(((((/((/**/  .**,/((((%%#####%%#%&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@&&%@@@@@@@@@@&&&&@@&&&&&&%((%((###*,,,*//((((#(/// ,(,  ,**//(###%%######%%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@&@&@@&&@@@@@@@@@@@@@@&@@&&&&&&&&&&&&&&&@&%*,,**//(((((((//*/*.,,/((((###%&&%%%%%&&@@@@@@@@@@@@@@@@@@@@@@@&%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@&@@@@@@&&&&&&@@@@/ ,,.,**(#(((###(((/*((##(####%&@@@@@@@@&%&@@@@@@@@@@@@@@@@@@@@@&%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@
)" << '\n';

}

void playTargetPractice( void ){
    // printBilly();
    cout << "Do you want to play a game?\ny/n\n" << endl;
    char answer;
    cin >> answer;
    switch (answer)
    {
    case 'y':
    {
        cout << message << endl;
        //Generate the target
        int targetDistance = randomWithLimits(100,1000);
        int attempts = 0;
        bool targetHit = false;
        //10 attempts to hit the target
        while (attempts<9 && targetHit == false)
        {   //Get the angle and velocity from the player
            double theta = getUserInputTheta();
            double absVelocity = getUserInputAbsVelocity();
            //Generate the veloctyVector with [x component, y component]
            vector<double> velocityVector = getVelocityVector(theta, absVelocity);
            //Check if the target is hit
            double distanceFromTarget = targetPractice(targetDistance, velocityVector.at(0),velocityVector.at(1));
            cannonBallViz(targetDistance, 1000, velocityVector.at(0), velocityVector.at(1),50);
            if (abs(distanceFromTarget) > 5.00)
            {
                // If the sign is positive, the player overshot, and if negative, the player undershot
                if (!signbit(distanceFromTarget))
                {
                    cout << "You overshot the target by: " << abs(distanceFromTarget) << " meters!" << endl;
                }
                else
                {
                    cout << "You undershot the target by: " << abs(distanceFromTarget) << " meters!" << endl;
                }
                
                cout << "The cannonball was in the ait for " << flightTime(velocityVector.at(1)) << " seconds!" << endl;
                attempts += 1;
            }
            else
            {
                targetHit = true;
                cout << "Target hit xddddd!\nYou won!!!" << endl;
            }
        }
        //After while loops exits, check wether or not target was hit
        if (targetHit != true)
        {
            cout << "You lost the game :(" << endl;
        }
        break;
    }
    case 'n':
        cout << "no game" << endl;
        break;
}
}
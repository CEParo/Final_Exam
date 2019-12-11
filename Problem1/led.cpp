#include "GPIO.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call
#include <cstdlib>
#include <cstdio>
#include <fcntl.h>
#include <sys/epoll.h>
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <unistd.h>
#define LED_GPIO "/sys/class/gpio/gpio60/"
using namespace std;
using namespace cgicc;
using namespace exploringBB;

GPIO *inGPIO;

int main(){
   Cgicc form;                      // the CGI form object
   
GPIO inGPIO(60);
inGPIO.setDirection(INPUT);
   char *value = getenv("REMOTE_ADDR");    // The remote IP address
 
   // generate the form but use states that are set in the submitted form
   cout << HTTPHTMLHeader() << endl;       // Generate the HTML form
   cout << html() << head() << title("Reading a GPIO pin") << head() << endl;
   cout << body() << h1("Exploring BB POST LED Example") << endl;;
   cout << "<form action=\"/cgi-bin/led.cgi\" method=\"POST\">\n";
   cout << "<input type=\"submit\" value=\"Read Switch\" />";
   cout << "</div></form>";

   inGPIO.getValue();
 
   // process the form data to change the LED state
   if (inGPIO.getValue() == HIGH)
	{
	 cout << html() << "ON" << html() << endl;
        }

   else cout << html() << "OFF" << html() << endl;
   cout << "<div> The CGI REMOTE_ADDR value is " << value << "</div>";
   cout << body() << html();
   return 0;
}

#include "epb_Container.h"


void epb::Container::a_multimap::removeApp(dictionary & dns,std::string pidstr)
{	
   dns.right.erase(pidstr);
}
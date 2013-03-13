#include <string>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>

namespace epb
{	
	namespace Container
	{
		struct bapppath {};
		struct bapppid {};
		class a_multimap
		{
		public:
			typedef boost::bimaps::bimap<   boost::bimaps::multiset_of < boost::bimaps::tagged< std::string,bapppath > >, boost::bimaps::tagged< std::string,bapppid >	> dictionary;
			typedef dictionary::value_type adjustment;
			void removeApp(dictionary & dns,std::string pidstr);
			

		};
	}
}
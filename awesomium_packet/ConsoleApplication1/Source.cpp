#include <boost/thread/thread.hpp>
#include <iostream>
#include <Windows.h>

#include <boost/assign/list_of.hpp>
#include <boost/assign/std/vector.hpp>
#include <boost/assert.hpp>


#include <boost/foreach.hpp>

#include <boost/functional/hash.hpp>


using namespace std;
using namespace boost::assign;
void hello();

class X {
  public:
    X(int i): val_(i) {}
    int get_val() const { return val_; }
  private:
    int val_;
};

//construct a hash function for class X
size_t hash_value(const X &x) 
{
  boost::hash<int> hasher;
  return hasher(x.get_val());
}
  


template <class Container>
std::vector<std::size_t> get_hashes(Container const& x)
{
    std::vector<std::size_t> hashes;
    std::transform(x.begin(), x.end(), std::insert_iterator(hashes),
        boost::hash<typename Container::value_type>());

    return hashes;
}

int main()
{ 	 
	
	/*
	boost::hash<std::string> string_hash;
	boost::hash<X> customerX_hash;
  
  //數學表述為：h = H(M) ，其中H( )--單向散列函數，M--任意長度明文，h--固定長度散列值。
  
	size_t h = string_hash("國");
	X x(44444444);	   	                    
	h = customerX_hash(x);
	cout << h << "\n";
	*/

  /*
	boost::hash<std::string> string_hash;
	boost::hash<double> double_hash;
	boost::hash<vector<int> > vector_hash;
	//hash for user defined type
	boost::hash<X> customerX_hash;
  
  //數學表述為：h = H(M) ，其中H( )--單向散列函數，M--任意長度明文，h--固定長度散列值。
  vector<int> v;
  
  
  size_t h = string_hash("hash me");
  cout << h << "\n";


  h = double_hash(3.1415927);
  cout << h << "\n";
  
  h = vector_hash(v);
  cout << h << "\n";
  
  v.push_back(10);
  h = vector_hash(v);
  cout << h << "\n";
                    
  h = customerX_hash(x);
  cout << h << "\n";
  */
	/*
	std::vector<int> values;  
    values += 1,2,3,4,5,6,7,8,9; // insert values at the end of the container
    BOOST_ASSERT( values.size() == 9 );
    BOOST_ASSERT( values[0] == 1 );
    BOOST_ASSERT( values[8] == 9 );

	vector<int> v;
    v += 1,2,3,repeat(10,4),5,6,7,8,9;
    // v = [1,2,3,4,4,4,4,4,4,4,4,4,4,5,6,7,8,9]
    BOOST_ASSERT( v.size() == 3 + 10 + 5 );
    
    v = list_of(1).repeat(5,2)(3);
    // v = [1,2,2,2,2,2,3]
    BOOST_ASSERT( v.size() == 1 + 5 + 1 );
    
    push_back( v )(1).repeat(1,2)(3);
    // v = old v + [1,2,3]
    BOOST_ASSERT( v.size() == 10 );

	
	BOOST_FOREACH( int i, v )
    {		
		cout << " " << i;
    }
	
	hello();

	
    boost::hash<std::string> string_hash;

    std::size_t h = string_hash("Hash me");

  */
	std::system("pause");
  return 0;
}


void hello()
{
	
	std::vector<int> deque_int;  
	deque_int += 0,1,2;
	int i = 0;
	BOOST_FOREACH( i, deque_int )
	{
		
		std::cout<<"------------------------"<<std::endl;
		std::cout<<"0"<<std::endl;
		if( i == 0 ) return;	
		std::cout<<"1"<<std::endl;
	    if( i == 1 ) continue;
		std::cout<<"2"<<std::endl;
	    if( i == 2 ) break;
		std::cout<<"3"<<std::endl;
	}

}

	//cout<<"hello"<<endl;
	//system("pause");
	/*
	while(true)
	{
		  boost::thread my_thread(&Players1);	
		  my_thread.join();
		 		  
		  Sleep(10);
		  
		  boost::thread my_thread2(&Players2);
		  my_thread2.join();
 
		  Sleep(10);
	}*/
void Players1() 
{
  std::cout << "Players1" << std::endl;
}

void Players2() 
{
  std::cout << "Players2" << std::endl;
}

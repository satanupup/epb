#ifndef _jge_singleton_20080205am1208_
#define _jge_singleton_20080205am1208_


_JGE_BEGIN


template<class T>
class TSingleton
{
protected:
	static	T*	mpSingleton;

public:
	TSingleton()
	{
		//assert(mpSingleton == 0);
		if(mpSingleton == 0)
		{
			mpSingleton = static_cast<T*>(this);
		}
	}

	~TSingleton()
	{
		//assert(mpSingleton);
		mpSingleton = 0;
	}

	static inline T* fnGetInstancePtr()
	{
		return mpSingleton;
	}

	static inline T& fnGetInstance()
	{
		//assert(mpSingleton);
		return *mpSingleton;
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T* TSingleton<T>::mpSingleton = 0;
///////////////////////////////////////////////////////////////////////////////////////////////
_JGE_END

#endif
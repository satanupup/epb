#ifndef _epb_singleton_20120622pm0945_
#define _epb_singleton_20120622pm0945_


_EPB_BEGIN


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
_EPB_END

#endif
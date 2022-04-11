#ifndef SINGLETON_H
#define SINGLETON_H

#include <assert.h>

template <class T>
class Singleton{
public:
    static T* Instance(){//Instance is object of class T
        if(!m_Instance) m_Instance = new T;//if m_Instance isn't defined or null then defines m_Instance as object of T.
        assert(m_Instance != NULL);// aborts if m_Instance = null
        return m_Instance;
    }

protected:
    Singleton();
    ~Singleton();
private:
    Singleton(Singleton const&);//copy constructor
    Singleton& operator=(Singleton const&);//copy assignment constructor
    Singleton(Singleton const&&);// move constructor
    Singleton& operator=(Singleton const&&);//move constructor
    //above constructor are defined in private ro forbid their use outside this class as it would create a error
    // we can define them in public access specifiers too using "=delete" at the end of them;

    static T* m_Instance;
};

template <class T>
T* Singleton<T>::m_Instance=NULL;



#endif // SINGLETON_H

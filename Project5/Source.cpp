#include <iostream>
#include <string>
using namespace std;
struct Entity
{
    
    virtual ~Entity() {}

     
    Entity(const  string& newName = "None")
        :mName(newName)
    {}
 
    const  string& GetName() const { return mName; }
    const  string& GetDirect() const { return mDirection; }

    void Display() const
    {
        std::cout << ClassName() << " '" << mName << "'\n";
    }

     
    void SetName(const  string& newName)
    {
         cout << "\n " << ClassName() << " '"
            << mName << "'s name now is '" << newName << "'";
        mName = newName;
    }

    void SetDirect(const  string& newDirect)
    {
        cout << "\n " << ClassName() << " '"
            << mName << "'s direction now is '" << newDirect << "'";
        mDirection = newDirect;
    }
protected:
 
    virtual const char* ClassName()const { return "Entity"; }

private:
     string mName;
     string mDirection;
};


struct EditableEntity : public Entity
{
    EditableEntity(const  string& NewName) : Entity(NewName) {}
protected:

    // наследник переопределяет метод
    virtual const char* ClassName()const { return "Editable Entity"; }
};


 
void foo(Entity& obj)
{
    obj.Display();
}

int main()
{
    Entity obj1("base");
    EditableEntity obj2("inheritor");

    foo(obj1);
    foo(obj2);
}
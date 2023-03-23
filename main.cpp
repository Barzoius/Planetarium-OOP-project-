#include <iostream>
#include <vector>
#include <cstring>


class Planet{

private:

    char* Name;
    int Diameter;
    long long S_P;

public:

    Planet()
    {
        Name = new char[(strlen("PRIME") + 1)];
            strcpy(Name, "PRIME");
        this -> Diameter = -100;
        this -> S_P = -100;
    }

    Planet(const char* n, int d, long long sp)
    {
        Name = new char[strlen(n) + 1];
            strcpy(Name, n);
        this -> Diameter = d;
        this -> S_P = sp;
    }

    const char* getName() const{ return Name; }
    int getDiameter() const { return Diameter; }
    long long getSP() const { return S_P; }

    void Stats() const
    {
        std::cout<<"Planet name: "<<getName()<<std::endl;
        std::cout<<"Planet diameter: "<<getDiameter()<<std::endl;
        std::cout<<"The distance between this planet and the star that is orbitating is: "<<getSP()<<" km"<<std::endl;
    }

};

class Satellite{

private:

    char* Name;
    int Diameter;
    int P_S;

public:

    Satellite()
    {
        Name = new char[strlen("BETA") + 1];
            strcpy(Name, "BETA");

    }

    Satellite(const char* n, int d, int ps)
    {
        Name = new char[strlen(n) + 1];
            strcpy(Name, n);
        this -> Diameter = d;
        this -> P_S = ps;
    }

    const char* getName() const { return Name; }
    int getDiameter() const { return Diameter; }
    int getPS() const { return P_S; }

    void Stats() const
    {
        std::cout<<"Satellite Name: "<<getName()<<std::endl;
        std::cout<<"Satellite Diameter: "<<getDiameter()<<std::endl;
        std::cout<<"The distance between this satellite and the planet that is orbitating is: "<<getPS()<<" km"<<std::endl;
    }

};

class PlanetSys{

private:

    Planet* oPlanet;
    std::vector<Satellite*> satellites;
    static bool Center;
    static bool exist;
    static Planet* CenterPlanet;
public:

    PlanetSys(Planet* P) : oPlanet(P)
    {
        if(exist)
        {
            throw std::logic_error("Such a planetary system already exists or is in creation.");
        }
        exist = true;
        CenterPlanet =  P;
        Center = true;
    }

    void addSatellite(Satellite* sat)
    {
        if(!Center)
        {
            throw std::logic_error("An central planet hasn't been added yet.");
        }

        satellites.push_back(sat);
    }

//    const Planet* getCentralPlanet() const
//    {
//        return oPlanet;
//    }

    std::vector<Satellite*> getSatellites() const
    {
        return satellites;
    }

    void printPlanetSys() const
    {
           std::cout<<"The Central Planet is: "<<oPlanet ->getName()<<std::endl;
           for(auto sat : satellites)
               std::cout<<"Satellite name: "<<sat -> getName()<<std::endl;
    }

};

bool PlanetSys::Center = false;
bool PlanetSys::exist = false;
Planet* PlanetSys::CenterPlanet = nullptr;


class Star{
    
private:
    char* Name;
    long long life_span;
    int Diameter;
    
public:
    
    Star() : Diameter(-100), life_span(0)
    {
        Name = new char[strlen("Sparky") + 1];
            strcpy(Name, "Sparky");
    }
    
    Star(const char* n, int d, long long ls) : Diameter(d), life_span(ls)
    {
        Name = new char[strlen(n) + 1];
            strcpy(Name, n);
    }
    
    const char* getName() const { return Name; }
    int getDiameter() const { return Diameter; }
    long long getLS() const { return life_span;}
    
    void printStar() const 
    {
        std::cout<<"The name of the star: "<<getName()<<std::endl;
        std::cout<<"The diameter of the star is: "<<getDiameter()<<std::endl;
        std::cout<<"The life span of this star is: "<<getLS()<<std::endl;
    }
};

int main() {

    Planet* P1 = new Planet("EARTH", 5000, 15000000);

    PlanetSys* sys = new PlanetSys(P1);

    Satellite* S1 = new Satellite("MOON", 1000, 13223);
    Satellite* S2 = new Satellite("TITAN", 1230, 23223);

    sys->addSatellite(S1);
    sys->addSatellite(S2);

    sys->printPlanetSys();

    return 0;
}

#ifndef SOLAROBJECTSFACTORY_H
#define SOLAROBJECTSFACTORY_H

#include <SolarCore/SolarObjects/abstractsolarobject.h>

namespace SolarSystem
{
    // all math solar objects factory
    class SolarObjectsFactory final
    {
    public:

        // creates any object inherited from AbstractSolarObject
        template< typename SolarObject,
                  typename... Args,
                  typename = std::enable_if_t<
                      std::is_base_of<AbstractSolarObject,
                      std::remove_cv_t<SolarObject>>::value>>

        static std::shared_ptr<AbstractSolarObject> create(Args&&... args)
        {
            using Type = typename std::remove_cv_t<SolarObject>;
            return std::make_shared<Type>(std::forward<Args>(args)...);
        }
    };
}

#endif // SOLAROBJECTSFACTORY_H

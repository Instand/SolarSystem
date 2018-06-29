#ifndef SOLAROBJECTSFACTORY_H
#define SOLAROBJECTSFACTORY_H

#include "SolarCore/SolarObjects/abstractsolarobject.h"

namespace SolarSystem
{
    //creates all math solar objects
    class SolarObjectsFactory final
    {
    public:

        //create any object inherited from AbstractSolarObject
        template< typename SolarObject,
                  typename... Args,
                  typename = std::enable_if_t<
                      std::is_base_of<AbstractSolarObject,
                      std::remove_cv_t<SolarObject>>::value>>

        static inline constexpr std::shared_ptr<AbstractSolarObject> create(Args&&... args)
        {
            typedef typename std::remove_cv_t<SolarObject> SolarT;
            return std::make_shared<SolarT>(std::forward<Args>(args)...);
        }
    };
}

#endif // SOLAROBJECTSFACTORY_H

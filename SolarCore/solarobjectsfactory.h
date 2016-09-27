#ifndef SOLAROBJECTSFACTORY_H
#define SOLAROBJECTSFACTORY_H

#include "SolarCore/SolarObjects/abstractsolarobject.h"

namespace SolarSystem {

    //creates all math solar objects
    class SolarObjectsFactory final {

    public:

        //create any object inherited from AbstractSolarObject
        template< typename _SolarObject,
                  typename... _Args,
                  typename = std::enable_if_t<
                      std::is_base_of<AbstractSolarObject,
                      std::remove_cv_t<_SolarObject>>::value>>

        static inline constexpr std::shared_ptr<AbstractSolarObject> create(_Args&&... _args) {

            typedef typename std::remove_cv_t<_SolarObject> _SolarT;
            return std::make_shared<_SolarT>(std::forward<_Args>(_args)...);

        }

    };
}

#endif // SOLAROBJECTSFACTORY_H

#ifndef SOLAROBJECTS_H
#define SOLAROBJECTS_H

#include "Core/SolarObjects/abstractsolarobject.h"

namespace SolarSystem
{
    namespace Stars
    {
        // Sun the center of solar sytem
        class Sun final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Sun(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };
    }

    namespace Planets
    {
        class Mercury final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Mercury(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        class Venus final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Venus(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        class Earth final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Earth(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        class Mars final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Mars(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        class Jupiter final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Jupiter(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        class Saturn final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Saturn(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        class Uranus final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Uranus(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        class Neptune final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Neptune(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        class Pluto final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Pluto(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

    }

    namespace Moons
    {
        class Moon final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            explicit Moon(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;

        };
    }
}


#endif // SOLAROBJECTS_H

#ifndef SOLAROBJECTS_H
#define SOLAROBJECTS_H

#include "SolarCore/SolarObjects/abstractsolarobject.h"

namespace SolarSystem
{
    namespace Stars
    {
        //Sun the center of solar sytem
        class Sun final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            Sun(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };
    }

    namespace Planets
    {
        //Mercury
        class Mercury final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            Mercury(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        //Venus
        class Venus final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            Venus(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        //Earth
        class Earth final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            Earth(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        //Mars
        class Mars final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            Mars(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        //Jupiter
        class Jupiter final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            Jupiter(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        //Saturn
        class Saturn final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            Saturn(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        //Uranus
        class Uranus final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            Uranus(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        //Neptune
        class Neptune final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            Neptune(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;
        };

        //Pluto
        class Pluto final : public AbstractSolarObject
        {
            Q_OBJECT

        public:
            Pluto(QObject* parent = nullptr);

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
            Moon(QObject* parent = nullptr);

        protected:
            virtual void initialize() override;

        };
    }
}


#endif // SOLAROBJECTS_H

#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include <Qt3DCore/QEntity>

namespace SolarSystem
{
    ///Caclcualtes fps
    class FpsCounter : public Qt3DCore::QEntity
    {
        Q_OBJECT

        Q_PROPERTY(int fps READ fps NOTIFY fpsChanged)

    public:
        explicit FpsCounter(Qt3DCore::QNode* parent = nullptr);
        virtual ~FpsCounter();

        ///returns fps value
        int fps() const;

    private:

        //fps data
        class FpsData;
        FpsData* fpsData;

    signals:

        ///fps can be read
        void fpsChanged(int fps);
    };
}

#endif // FPSCOUNTER_H

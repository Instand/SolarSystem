#ifndef SOLARDIFFUSEEFFECT_H
#define SOLARDIFFUSEEFFECT_H

#include <Qt3DRender/QEffect>

namespace SolarSystem {

    //diffuse without light
    class SolarDiffuseEffect : public Qt3DRender::QEffect
    {
        Q_OBJECT

    public:
        SolarDiffuseEffect(Qt3DCore::QNode* parent = nullptr);
    };
}

#endif // SOLARDIFFUSEEFFECT_H

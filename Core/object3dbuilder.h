#ifndef OBJECT3DBUILDER_H
#define OBJECT3DBUILDER_H

#include <Qt3DRender/QTexture>

#include <solarsystemcore.h>

#include <Scene/SceneObjects/planet.h>
#include <Scene/SceneObjects/planetring.h>

namespace SolarSystem
{
    template <typename Object, typename Material>
    class Object3DBuilder
    {
    public:
        Object3DBuilder() {}
        Object3DBuilder(const QString& diffuse, const QString& normal = QString()):
            m_normalSource(normal),
            m_diffuseSource(diffuse)
        {
        }

        Object3DBuilder& setShiness(float shiness)
        {
            m_shiness = shiness;
            return *this;
        }

        Object3DBuilder& setNormalSource(const QString& normalSource)
        {
            m_normalSource = normalSource;
            return *this;
        }

        Object3DBuilder& setDiffuseSource(const QString& diffuseSource)
        {
            m_diffuseSource = diffuseSource;
            return *this;
        }

        Object3DBuilder& setTilt(double tilt)
        {
            m_tilt = tilt;
            return *this;
        }

        // create and setup planet
        Object* build(Qt3DCore::QNode* root = nullptr)
        {
            Object* object = new Object(root);

            auto material = qobject_cast<Material*>(object->material());

            // diffuse
            if (!m_diffuseSource.isEmpty())
            {
                Qt3DRender::QTextureImage* diffuse = new Qt3DRender::QTextureImage(object);
                diffuse->setSource(QUrl::fromLocalFile(m_diffuseSource));
                material->diffuse()->addTextureImage(diffuse);
            }

            // normal
            if (!m_normalSource.isEmpty())
            {
                Qt3DRender::QTextureImage* normal = new Qt3DRender::QTextureImage(object);
                normal->setSource(QUrl::fromLocalFile(m_normalSource));
                material->normal()->addTextureImage(normal);
            }

            if (m_shiness != 0.0f)
                material->setShininess(material->shininess() * m_shiness);

            if (m_tilt != 0.0)
                object->setTilt(m_tilt);

            return object;
        }

    private:
        QString m_normalSource;
        QString m_diffuseSource;
        float m_shiness = 0;
        double m_tilt = 0;
    };

    using PlanetBuilder = Object3DBuilder<Planet, Qt3DExtras::QNormalDiffuseMapMaterial>;
    using PlanetRingBuilder = Object3DBuilder<PlanetRing, Qt3DExtras::QNormalDiffuseMapAlphaMaterial>;
}

#endif // OBJECT3DBUILDER_H

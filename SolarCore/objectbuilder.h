#ifndef PLANETBUILDER_H
#define PLANETBUILDER_H

#include <Qt3DRender/QTexture>

#include <solarsystemcore.h>

#include <Scene/SceneObjects/planet.h>
#include <Scene/SceneObjects/planetring.h>

namespace SolarSystem
{
    template <typename Object, typename Material>
    class ObjectBuilder
    {
    public:
        ObjectBuilder() {}
        ObjectBuilder(const QString& diffuse, const QString& normal = QString()):
            m_normalSource(normal),
            m_diffuseSource(diffuse)
        {
        }

        void setShiness(float shiness)
        {
            m_shiness = shiness;
        }

        void setNormalSource(const QString& normalSource)
        {
            m_normalSource = normalSource;
        }

        void setDiffuseSource(const QString& diffuseSource)
        {
            m_diffuseSource = diffuseSource;
        }

        void setTilt(double tilt)
        {
            m_tilt = tilt;
        }

        // create and setup planet
        void build(Qt3DCore::QNode* root)
        {
            if (!m_object)
            {
                m_object = new Object(root);

                auto material = qobject_cast<Material*>(m_object->material());

                // diffuse
                if (!m_diffuseSource.isEmpty())
                {
                    Qt3DRender::QTextureImage* diffuse = new Qt3DRender::QTextureImage();
                    diffuse->setSource(QUrl::fromLocalFile(m_diffuseSource));
                    material->diffuse()->addTextureImage(diffuse);
                }

                // normal
                if (!m_normalSource.isEmpty())
                {
                    Qt3DRender::QTextureImage* normal = new Qt3DRender::QTextureImage();
                    normal->setSource(QUrl::fromLocalFile(m_normalSource));
                    material->normal()->addTextureImage(normal);
                }

                //mars material setup
                if (m_shiness != 0.0f)
                    material->setShininess(material->shininess() * m_shiness);

                if (m_tilt != 0.0)
                    m_object->setTilt(m_tilt);
            }
        }

        // returns created planet or nullptr
        Object* object() const
        {
            return m_object;
        }

    private:
        QString m_normalSource;
        QString m_diffuseSource;
        float m_shiness = 0;
        double m_tilt = 0;

        Object* m_object = nullptr;
    };

    using PlanetBuilder = ObjectBuilder<Planet, Qt3DExtras::QNormalDiffuseMapMaterial>;
    using PlanetRingBuilder = ObjectBuilder<PlanetRing, Qt3DExtras::QNormalDiffuseMapAlphaMaterial>;
}

#endif // PLANETBUILDER_H

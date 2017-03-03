#include "solar3dalphaobject.h"

SolarSystem::Solar3DAlphaObject::Solar3DAlphaObject(Qt3DCore::QNode *parent):
    BaseVisualSolarObject(parent),
  _picker(new Qt3DRender::QObjectPicker()),
  _material(new Qt3DExtras::QNormalDiffuseMapAlphaMaterial()),
  _diffuse(new Qt3DRender::QTextureImage())
{
  _material->diffuse()->addTextureImage(_diffuse);

  _picker->setDragEnabled(false);
  _picker->setHoverEnabled(false);
  _picker->setEnabled(true);

  addComponent(_material);
  addComponent(_picker);
}

Qt3DRender::QObjectPicker &SolarSystem::Solar3DAlphaObject::picker() const
{
  return *_picker;
}

Qt3DExtras::QNormalDiffuseMapAlphaMaterial &SolarSystem::Solar3DAlphaObject::material() const
{
  return *_material;
}

Qt3DRender::QTextureImage& SolarSystem::Solar3DAlphaObject::diffuse() const
{
  return *_diffuse;
}

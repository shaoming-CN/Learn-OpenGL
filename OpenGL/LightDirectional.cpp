#include "LightDirectional.h"

LightDirectional::LightDirectional(glm::vec3 _angles, glm::vec3 _color) :
	angles(_angles),
	color(_color)
{
	UpdateDiection();
}

void LightDirectional::UpdateDiection() {
	direction = glm::vec3(0, 0, 1.0f);//���ǹ��߷���
	direction = glm::rotateZ(direction, glm::radians(angles.z));
	direction = glm::rotateX(direction, glm::radians(angles.x));
	direction = glm::rotateY(direction, glm::radians(angles.y));
	//����ָ���ķ���������෴��
	direction *= -1.0f;
}
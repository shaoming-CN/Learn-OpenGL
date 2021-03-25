#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldup)
{
	Position = position;
	WorldUp = worldup;
	//normalize ��һ����ɵ�λ����
	//Forward ��Ӱ���ġ����򡱣�һ���ͳ����෴��������
	Forward = glm::normalize(position - target);
	//Right ������Camera���ҷ�����������Ϸ�������Ӱ��������
	Right = glm::normalize(glm::cross(WorldUp, Forward));
	//UP  ��������Ϸ���
	Up = glm::cross(Forward, Right);
}

glm::mat4 Camera::GetViewMatrix()
{
	//glm::LookAt������Ҫһ�������λ�á�һ��Ŀ��λ�úͱ�ʾ����ռ��е���������������
	//���ᴴ��һ���۲����
	return glm::lookAt(Position, Position - Forward, WorldUp);
}

Camera::Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup)
{
	Position = position;
	WorldUp = worldup;
	Pitch = pitch;
	Yaw = yaw;
	Forward.x = cos(glm::radians(Pitch)) * sin(glm::radians(Yaw));
	Forward.y = sin(glm::radians(Pitch));
	Forward.z = cos(glm::radians(Pitch)) * cos(glm::radians(Yaw));
	Forward = glm::normalize(Forward);
	//Right ������������ռ��x���������
	Right = glm::normalize(glm::cross(WorldUp, Forward));
	//UP һ��ָ�����������y������
	Up = glm::cross(Forward, Right);
}

void Camera::ProcessMouseMovement(float deltaX, float deltaY)
{
	Pitch += deltaY;
	Yaw -= deltaX;

	UpdateCameraVectors();
	if (Pitch > 89.0f)
		Pitch = 89.0f;
	if (Pitch < -89.0f)
		Pitch = -89.0f;
}

//-Forward�ǵ�ǰ����ĳ���
//��ǰ
void Camera::PosUpdateForward()
{
	Position += cameraPosSpeed * -Forward;
}
//����
void Camera::PosUpdateBackward()
{
	Position -= cameraPosSpeed * -Forward;
}
//����
void Camera::PosUpdateUp()
{
	Position += cameraPosSpeed * WorldUp;
}
//����
void Camera::PosUpdateDown()
{
	Position -= cameraPosSpeed * WorldUp;
} 
//���
void Camera::PosUpdateLeft()
{
	Position -= glm::normalize(glm::cross(-Forward, Up)) * cameraPosSpeed;
}
//�ұ�
void Camera::PosUpdateRight()
{
	Position += glm::normalize(glm::cross(-Forward, Up)) * cameraPosSpeed;
}


void Camera::UpdateCameraVectors()
{
	Forward.x = cos(glm::radians(Pitch)) * sin(glm::radians(Yaw));
	Forward.y = sin(glm::radians(Pitch));
	Forward.z = cos(glm::radians(Pitch)) * cos(glm::radians(Yaw));
	Forward = glm::normalize(Forward);
	//Right ������������ռ��x���������
	Right = glm::normalize(glm::cross(WorldUp, Forward));
	//UP һ��ָ�����������y������
	Up = glm::cross(Forward, Right);
}


Camera::~Camera()
{
}
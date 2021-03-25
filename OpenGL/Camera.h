#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	~Camera();
	//position �������λ��  target ���ָ���λ��  worldup �������ϵ�����
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldup);
	//pitch�����Ǻ�yawƫ����
	Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup);


	//��Ӱ��λ��
	glm::vec3 Position;
	//Forward ��Ӱ���ġ����򡱣�һ���ͳ����෴��������
	glm::vec3 Forward;
	glm::vec3 Right;
	//��Ӱ�����Ϸ���
	glm::vec3 Up;
	//������Ϸ���
	glm::vec3 WorldUp;
	float Pitch;
	float Yaw;
	float cameraPosSpeed;


	glm::mat4 GetViewMatrix();
	void ProcessMouseMovement(float deltaX, float deltaY);
	void PosUpdateForward();
	void PosUpdateBackward();
	void PosUpdateLeft();
	void PosUpdateRight();
	void PosUpdateUp();
	void PosUpdateDown();

private:
	void UpdateCameraVectors();
};
#pragma once
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	std::string vertexString;
	std::string fragmentString;
	const char* vertexSource;
	const char* fragmentSource;
	unsigned int ID;  //Shader Program ID

	void use();
	void SetUniform3f(const char* paraNameString, glm::vec3 param);
	void SetUniform1f(const char* paraNameString, float param);
	void SetUniform1i(const char* paraNameString, int slot);
	//~Shader();
private:
	void checkCompileErrors(unsigned int ID, std::string type);
};
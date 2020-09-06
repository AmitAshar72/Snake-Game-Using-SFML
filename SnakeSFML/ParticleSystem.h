#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include <random>

#define PI 3.14;
struct particlesProp
{
	sf::Vector2f Position;
	sf::Vector2f Veclocity, VelocityVariation;
	sf::Color colorBegin, colorEnd;
	float sizeBegin, SizeEnd, Sizevariation;
	float lifeTime = 1.0f;
};
class ParticleSystem
{	
public:
	ParticleSystem();

	void update(float delTime);
	void render();

	void emissions(const particlesProp& p, std::mt19937& rng);
private:
	struct particle
	{
		sf::Vector2f Position;
		sf::Vector2f Veclocity;
		sf::Color colorBegin, colorEnd;
		float rotation = 0.0f;
		float sizeBegin, SizeEnd;
		float lifeTime = 1.0f;
		float lifeRemaining = 0.0f;
		bool active = false;
	};
	std::vector<particle> m_particlePool;
	uint32_t m_poolIndex = 999;
	
	GLuint m_QuadVA = 0;
	std::unique_ptr<sf::Shader> m_particleShader;
	GLint m_ParticleShaderViewProj, m_ParticleShaderTransform, m_ParticleShaderColor;
};


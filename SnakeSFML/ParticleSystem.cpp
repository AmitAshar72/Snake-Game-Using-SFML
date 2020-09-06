#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
	m_particlePool.resize(1000);
}

void ParticleSystem::update(float delTime)
{
	for (auto& particle : m_particlePool)
	{
		if (!particle.active)
		{
			continue;
		}
		if (particle.lifeRemaining <= 0.0f)
		{
			particle.active = false;
			continue;
		}

		particle.lifeRemaining -= delTime;
		particle.Position += particle.Veclocity*(float)delTime;
		particle.rotation += 0.01f*delTime;
	}
}

void ParticleSystem::render()
{
	
}

void ParticleSystem::emissions(const particlesProp& p, std::mt19937& rng)
{
	//std::uniform_int_distribution<float> rand(0.0f, 360.0f);
	//std::uniform_int_distribution<float> xVar(-0.5f, 0.51f);
	//std::uniform_int_distribution<float> yVar(-0.5f, 0.51f);
	//std::uniform_int_distribution<float> size(-0.5f, 0.51f);
	//particle& particle = m_particlePool[m_poolIndex];
	//particle.active = true;
	//particle.Position = p.Position;
	//particle.rotation= rand(rng) * 2.0f * PI  ; //random	

	////velocity
	//particle.Veclocity = p.Veclocity;
	//particle.Veclocity.x = p.VelocityVariation.x * xVar(rng);
	//particle.Veclocity.y = p.VelocityVariation.y * yVar(rng);

	////color
	//particle.colorBegin = p.colorBegin;
	//particle.colorEnd = p.colorEnd;

	//particle.lifeTime = p.lifeTime;
	//particle.lifeRemaining = p.lifeTime;
	//particle.sizeBegin = p.sizeBegin + p.Sizevariation*size(rng);
	//particle.SizeEnd = p.SizeEnd;

	//m_poolIndex = --m_poolIndex % m_particlePool.size();
}

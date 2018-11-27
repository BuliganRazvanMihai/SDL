#pragma once
namespace razvan {
	struct Particle
	{
		double m_x;//pozitie lui x
		double m_y;//pozitia lui y
	private:
		double m_speed;
		double m_direction;
	private:
		void init();
	public:
		Particle();
		~Particle();
		void update(int interval);
	};
}

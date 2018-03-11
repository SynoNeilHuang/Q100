#ifndef __Q45__
#define __Q45__
class Singleton {
	public:
		static Singleton* getInstance();
	private:
		Singleton() {};
		virtual ~Singleton() {};
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton &source);
};

#endif /* __Q45__ */

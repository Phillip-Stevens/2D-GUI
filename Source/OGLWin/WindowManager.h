#include <vector>
#include "MainMenu.h"
#include "Options.h"

class WindowManager
{
	private:
		static WindowManager*			s_wndmgr; //A singleton maintains a pointer to itself as a class variable
		std::vector<GUIItem*>			m_guilist; //storage for gui item

		MainMenu *m_mainMenu;
		Options *m_optionsMenu;
		bool m_optionsCreated;

		//To ensure the integrity of a singleton
		//Constructors and the destructor should remain private
		WindowManager();
		~WindowManager();

	public:
		static void Create();
		static void Destroy();
		static inline WindowManager* Get()
		{
			return s_wndmgr;
		}

		void Render();
		void MouseMove(float x, float y);
		void MouseLBDown(float x, float y);
		void SwitchBoard(int option);
		void MouseLBUp(float x, float y);

		void AddItem(GUIItem* item);
		void RemoveItem(GUIItem * item);
};

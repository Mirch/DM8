#pragma once

#include <../DM8.h>

namespace DM8CLI
{

	static const char* string_to_char_array(System::String^ string)
	{
		char* result = new char[string->Length + 1];
		sprintf(result, "%s", string);
		return result;
	}


	template<typename T>
	public ref class DMManagedObject
	{
	protected:
		T* m_Instance;
	public:
		DMManagedObject()
		{

		}
		DMManagedObject(T* instance)
			: m_Instance(instance)
		{

		}

		virtual ~DMManagedObject()
		{
			if (m_Instance != nullptr)
			{
				delete m_Instance;
			}
		}

		!DMManagedObject()
		{
			if (m_Instance != nullptr)
			{
				delete m_Instance;
			}
		}

		T* GetHandle()
		{
			return m_Instance;
		}


	};

}


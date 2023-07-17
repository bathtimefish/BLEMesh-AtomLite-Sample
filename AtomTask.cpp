#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <string>

#include "AtomTask.h"

static char tag[] = "Task";

AtomTask::AtomTask(std::string taskName, uint16_t taskSize, uint8_t priority)
{
	m_handle 	= nullptr;
	m_taskdata 	= nullptr;
	m_taskname	= taskName;
	m_tasksize 	= taskSize;
	m_priority 	= priority;
	m_coreid	= tskNO_AFFINITY;
}

AtomTask::~AtomTask()
{
}

void AtomTask::runTask(void* pTaskInstance)
{
	AtomTask* pTask = (AtomTask*)pTaskInstance;
	ESP_LOGD(tag, ">> Task %s run", pTask->m_taskname.c_str());
	pTask->run(pTask->m_taskdata);
	ESP_LOGD(tag, "<< Task %s stop", pTask->m_taskname.c_str());
	pTask->stop();
}

void AtomTask::start(void* taskData)
{
	if( m_handle != nullptr )
	{
		ESP_LOGD(tag, "[] Task %s is already running", m_taskname.c_str());
	}
	m_taskdata = taskData;
	::xTaskCreatePinnedToCore(&runTask, m_taskname.c_str(), m_tasksize, this, m_priority, &m_handle, m_coreid);
}

void AtomTask::stop()
{
	if( m_handle == nullptr )
	{
		return;
	}
	xTaskHandle handleTemp = m_handle;
	m_handle = nullptr;
	::vTaskDelete(handleTemp);
}

void AtomTask::delay(int ms)
{
	::vTaskDelay(ms/portTICK_PERIOD_MS);
}

void AtomTask::setTaskSize( uint16_t size )
{
	m_tasksize = size;
}

void AtomTask::setTaskPriority( uint8_t priority)
{
	m_priority = priority;
}

void AtomTask::setTaskName(std::string name)
{
	m_taskname = name;
}

void AtomTask::setCore(BaseType_t coreID)
{
	m_coreid = coreID;
}


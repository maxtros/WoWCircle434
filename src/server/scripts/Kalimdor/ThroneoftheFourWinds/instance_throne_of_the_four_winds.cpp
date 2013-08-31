#include "ScriptPCH.h"
#include "throne_of_the_four_winds.h"

#define MAX_ENCOUNTER 2

static const DoorData doordata[] = 
{
    {0, 0, DOOR_TYPE_ROOM, BOUNDARY_NONE},
};

class instance_throne_of_the_four_winds : public InstanceMapScript
{
public:
    instance_throne_of_the_four_winds() : InstanceMapScript("instance_throne_of_the_four_winds", 754) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_throne_of_the_four_winds_InstanceMapScript(map);
    }

    struct instance_throne_of_the_four_winds_InstanceMapScript : public InstanceScript
    {
        instance_throne_of_the_four_winds_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);
            LoadDoorData(doordata);
        }

        void OnPlayerEnter(Player* pPlayer)
        {
            if (!uiTeamInInstance)
                uiTeamInInstance = pPlayer->GetTeam();
        }

        void OnCreatureCreate(Creature* pCreature)
        {
        }

        void OnGameObjectCreate(GameObject* pGo)
        {
        }

        void OnGameObjectRemove(GameObject* pGo)
        {
        }

        void SetData(uint32 type, uint32 data)
        {
        }

        uint32 GetData(uint32 type)
        {
            return 0;
        }

        uint64 GetData64(uint32 type)
        {
            return 0;
        }

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            return true;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::string str_data;

            std::ostringstream saveStream;
            saveStream << "T o t F W " << GetBossSaveData();

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2, dataHead3, dataHead4, dataHead5;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> dataHead3 >> dataHead4 >> dataHead5;

            if (dataHead1 == 'T' && dataHead2 == 'o' && dataHead2 == 't' && dataHead2 == 'F' && dataHead2 == 'W')
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }} else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        private:
            uint32 uiTeamInInstance;
           
    };
};

void AddSC_instance_throne_of_the_four_winds()
{
       new instance_throne_of_the_four_winds();
}
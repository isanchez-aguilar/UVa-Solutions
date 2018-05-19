/*
*	User: Isanchez_Aguilar
*	Problem: UVA 857 - Quantiser
*/
#include <bits/stdc++.h>

using namespace std;

class Event {
public:
	Event()
	{
	}
	Event(bool _code, int _note, int _measure, int _beat, int _tick)
	{
		code = _code;
		note = _note;
		measure = _measure;
		beat = _beat;
		tick = _tick;
	}
	bool code;
	int note;
	int measure;
	int beat;
	int tick;
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	while (cin >> n and n != -1)
	{
		vector<Event> events(n);
		
		for (int i = 0; i < n; ++i)
		{
			int note;
			int beat;
			int tick;
			bool code;
			int measure;
			cin >> code >> note >> measure >> beat >> tick;
			
			tick = (tick + 30) / 60 * 60;
			
			if (tick == 480)
			{
				tick = 0;
				
				if (++beat == 5)
				{
					beat = 1;
					++measure;
				}
			}
			
			events[i] = Event(code, note, measure, beat, tick);
		}
		
		for (vector<Event>::iterator i = events.begin(); i != events.end(); ++i)
		{
			if (i->code)
			{
				for (vector<Event>::iterator j = i + 1; j != events.end(); ++j)
				{
					if (i->note == j->note and i->code and not j->code)
					{
						
						if (i->measure == j->measure and i->beat == j->beat and i->tick == j->tick)
						{
							
							i = events.erase(i);
							i--;
							j--;
							j = events.erase(j);
							j--;
						}
						
						break;
					}
				}
			}
		}
		
		cout << events.size() << "\n";
		
		for (vector<Event>::iterator i = events.begin(); i != events.end(); ++i)
			cout << i->code << " " << i->note << " " << i->measure << " " << i->beat << " " << i-> tick << "\n";
	}
	
	cout << "-1\n";
	
	return 0;
}

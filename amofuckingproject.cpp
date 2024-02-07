#include <iostream>
#include <portaudio.h>
#include <conio.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 256
#define FILENAME "audio.wav"

using namespace std;

int main()
{

	return 0;
}

void newstream()
{
	PaStream *stream;
	PaError err;
	err = Pa_Initialize();
	if (err != paNoError)
	{
		cerr << "Проебал иницализацию, ебло утиное, лови ошибку: " << Pa_GetErrorText(err) << endl;
	}

	//входные блять параметры
	PaStreamParameters inputParameters;
	inputParameters.device = Pa_GetDefaultInputDevice();
	inputParameters.channelCount = 2; // Стерео нахуй
	inputParameters.sampleFormat = paFloat32;
	inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultHighInputLatency;
	inputParameters.hostApiSpecificStreamInfo = nullptr;
	
	//выходные сука параметры
	PaStreamParameters outputParameters;
	outputParameters.device = Pa_GetDefaultOutputDevice();
	outputParameters.channelCount = 2;
	outputParameters.sampleFormat = paFloat32;
	outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultHighOutputLatency;
	outputParameters.hostApiSpecificStreamInfo = nullptr;

	//Открытие ебучего потока
	err = Pa_OpenStream(&stream, &inputParameters, &outputParameters, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, callback, nullptr);
	if (err!=paNoError)
	{
		cerr << "Ты, сука, тупой блять или что? Проебал открытие потока, на тебе ошибку, тварь: " << Pa_GetErrorText(err) << endl;
	}

	//Старт потока
	err = Pa_StartStream(stream);
	if (err!=paNoError)
	{
		cerr << "Проебал старт потока, дуралей, на тебе ошибку на еблет: " << Pa_GetErrorText(err) << endl;
	}

	//

}

int callback(const void *input,
	void *output,
	unsigned long frames,
	const PaStreamCallbackTimeInfo *timinfo,
	PaStreamCallbackFlags statusFlags,
	void *userdata
	)
{

}





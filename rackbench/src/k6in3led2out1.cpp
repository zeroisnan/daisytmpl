#include "plugin.hpp"


struct K6in3led2out1 : Module {
	enum ParamIds {
		P0_PARAM,
		P1_PARAM,
		P2_PARAM,
		P3_PARAM,
		P4_PARAM,
		P5_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		CV0_INPUT,
		CV1_INPUT,
		CV2_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		OUT_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		LED0_LIGHT,
		LED1_LIGHT,
		NUM_LIGHTS
	};

	K6in3led2out1() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
		configParam(P0_PARAM, 0.f, 1.f, 0.f, "");
		configParam(P1_PARAM, 0.f, 1.f, 0.f, "");
		configParam(P2_PARAM, 0.f, 1.f, 0.f, "");
		configParam(P3_PARAM, 0.f, 1.f, 0.f, "");
		configParam(P4_PARAM, 0.f, 1.f, 0.f, "");
		configParam(P5_PARAM, 0.f, 1.f, 0.f, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct K6in3led2out1Widget : ModuleWidget {
	K6in3led2out1Widget(K6in3led2out1* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/k6in3led2out1.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(15.24, 25.81)), module, K6in3led2out1::P0_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(45.72, 25.81)), module, K6in3led2out1::P1_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(76.2, 25.81)), module, K6in3led2out1::P2_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(15.24, 55.81)), module, K6in3led2out1::P3_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(45.72, 55.81)), module, K6in3led2out1::P4_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(76.2, 55.81)), module, K6in3led2out1::P5_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(15.24, 83.713)), module, K6in3led2out1::CV0_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(45.72, 83.713)), module, K6in3led2out1::CV1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(76.2, 83.713)), module, K6in3led2out1::CV2_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(45.72, 108.713)), module, K6in3led2out1::OUT_OUTPUT));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(15.24, 108.713)), module, K6in3led2out1::LED0_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(76.2, 108.713)), module, K6in3led2out1::LED1_LIGHT));
	}
};


Model* modelK6in3led2out1 = createModel<K6in3led2out1, K6in3led2out1Widget>("k6in3led2out1");
#include "esphome.h"

class SDMComponent : public PollingComponent {
public:
  SDM sdm = SDM(Serial, 9600, NOT_A_PIN, SERIAL_8N1, false);
  /*Voltage*/
  Sensor *voltage_sensor_1 = new Sensor();
  Sensor *voltage_sensor_2 = new Sensor();
  Sensor *voltage_sensor_3 = new Sensor();
  /*Current*/
  Sensor *current_sensor_1 = new Sensor();
  Sensor *current_sensor_2 = new Sensor();
  Sensor *current_sensor_3 = new Sensor();
  Sensor *currentsum_sensor = new Sensor();
  //Power
  Sensor *power_sensor_1 = new Sensor();
  Sensor *power_sensor_2 = new Sensor();
  Sensor *power_sensor_3 = new Sensor();
  Sensor *powersum_sensor = new Sensor();
  //Vars
  Sensor *vars_sensor_1 = new Sensor();
  Sensor *vars_sensor_2 = new Sensor();
  Sensor *vars_sensor_3 = new Sensor();
  Sensor *varssum_sensor = new Sensor();
  //frequency
  Sensor *frequency_sensor = new Sensor();
  //import export energy
  Sensor *active_energy_import_sensor = new Sensor();
  Sensor *active_energy_export_sensor = new Sensor();
  Sensor *reactive_energy_import_sensor = new Sensor();
  Sensor *reactive_energy_export_sensor = new Sensor();
  Sensor *import_kwh_sensor_1 = new Sensor();
  Sensor *import_kwh_sensor_2 = new Sensor();
  Sensor *import_kwh_sensor_3 = new Sensor();
  Sensor *importsum_kwh_sensor = new Sensor();
  Sensor *export_kwh_sensor_1 = new Sensor();
  Sensor *export_kwh_sensor_2 = new Sensor();
  Sensor *export_kwh_sensor_3 = new Sensor();
  Sensor *exportsum_kwh_sensor = new Sensor();
  //power factor
  Sensor *power_factor_sensor_1 = new Sensor();
  Sensor *power_factor_sensor_2 = new Sensor();
  Sensor *power_factor_sensor_3 = new Sensor();
  Sensor *power_factor_total_sensor = new Sensor();
  //Energy kWh
  Sensor *energy_total_sensor_1 = new Sensor();
  Sensor *energy_total_sensor_2 = new Sensor();
  Sensor *energy_total_sensor_3 = new Sensor();
  Sensor *energy_totalsum_sensor = new Sensor();

  SDMComponent() : PollingComponent(15000) {}

  void setup() override {
    ESP_LOGD("SDM", "Setup completed");
  }

  void update() override {
//    ESP_LOGD("SDM", "Start reading");
    float voltage1 = sdm.readVal(SDM630_VOLTAGE1);
    float voltage2 = sdm.readVal(SDM630_VOLTAGE2);
    float voltage3 = sdm.readVal(SDM630_VOLTAGE3);
//    ESP_LOGD("SDM", "Voltages %f %f %f", voltage1, voltage2, voltage3);
    voltage_sensor_1->publish_state(voltage1);
    voltage_sensor_2->publish_state(voltage2);
    voltage_sensor_3->publish_state(voltage3);
	
    float current1 = sdm.readVal(SDM630_CURRENT1);
	float current2 = sdm.readVal(SDM630_CURRENT2);
	float current3 = sdm.readVal(SDM630_CURRENT3);
    current_sensor_1->publish_state(current1);
	current_sensor_2->publish_state(current2);
	current_sensor_3->publish_state(current3);

    float power1 = sdm.readVal(SDM630_POWER1);
	float power2 = sdm.readVal(SDM630_POWER2);
	float power3 = sdm.readVal(SDM630_POWER3);
	float powersum = sdm.readVal(SDM630_POWERTOTAL);
    power_sensor_1->publish_state(power1);
	power_sensor_2->publish_state(power2);
	power_sensor_3->publish_state(power3);
	powersum_sensor->publish_state(powersum);
	
	float vars1 = sdm.readVal(SDM630_VOLT_AMPS_REACTIVE1);
	float vars2 = sdm.readVal(SDM630_VOLT_AMPS_REACTIVE2);
	float vars3 = sdm.readVal(SDM630_VOLT_AMPS_REACTIVE3);
	float varssum = sdm.readVal(SDM630_VOLT_AMPS_REACTIVE_TOTAL);
    vars_sensor_1->publish_state(vars1);
	vars_sensor_2->publish_state(vars2);
	vars_sensor_3->publish_state(vars3);
	varssum_sensor->publish_state(varssum);

    float import1 = sdm.readVal(SDM630_IMPORT1);
    float import2 = sdm.readVal(SDM630_IMPORT2);
    float import3 = sdm.readVal(SDM630_IMPORT3);
//    ESP_LOGD("SDM", "Imports %f %f %f", import1, import2, import3);
	import_kwh_sensor_1->publish_state(import1);
	import_kwh_sensor_2->publish_state(import2);
	import_kwh_sensor_3->publish_state(import3);
    importsum_kwh_sensor->publish_state(import1 + import2 + import3);
	
	float export1 = sdm.readVal(SDM630_EXPORT1);
    float export2 = sdm.readVal(SDM630_EXPORT2);
    float export3 = sdm.readVal(SDM630_EXPORT3);
//    ESP_LOGD("SDM", "Exports %f %f %f", export1, export2, export3);
	export_kwh_sensor_1->publish_state(export1);
	export_kwh_sensor_2->publish_state(export2);
	export_kwh_sensor_3->publish_state(export3);
    exportsum_kwh_sensor->publish_state(export1 + export2 + export3);
	
	float frequency = sdm.readVal(SDM630_FREQUENCY);
	frequency_sensor->publish_state(frequency);
	
    float active_ene_import = sdm.readVal(SDM630_IMPORT_ACTIVE_ENERGY);
    float active_ene_export = sdm.readVal(SDM630_EXPORT_ACTIVE_ENERGY);
    float reactive_ene_import = sdm.readVal(SDM630_IMPORT_REACTIVE_ENERGY);
	float reactive_ene_export = sdm.readVal(SDM630_EXPORT_REACTIVE_ENERGY);
	active_energy_import_sensor->publish_state(active_ene_import);
	active_energy_export_sensor->publish_state(active_ene_export);
	reactive_energy_import_sensor->publish_state(reactive_ene_import);
    reactive_energy_export_sensor->publish_state(reactive_ene_export);

    float power_factor1 = sdm.readVal(SDM630_POWER_FACTOR1);
	float power_factor2 = sdm.readVal(SDM630_POWER_FACTOR2);
	float power_factor3 = sdm.readVal(SDM630_POWER_FACTOR3);
	float power_factor_total = sdm.readVal(SDM630_POWER_FACTOR_TOTAL);
    power_factor_sensor_1->publish_state(power_factor1);
	power_factor_sensor_2->publish_state(power_factor2);
	power_factor_sensor_3->publish_state(power_factor3);
	power_factor_total_sensor->publish_state(power_factor_total);

    float ene_total1 = sdm.readVal(SDM630_TOTAL_ENERGY1);
    float ene_total2 = sdm.readVal(SDM630_TOTAL_ENERGY2);
    float ene_total3 = sdm.readVal(SDM630_TOTAL_ENERGY3);
//ESP_LOGD("SDM", "Energy totals %f %f %f", ene_total1, ene_total1, ene_total1);
	energy_total_sensor_1->publish_state(ene_total1);
	energy_total_sensor_2->publish_state(ene_total2);
	energy_total_sensor_3->publish_state(ene_total3);
    energy_totalsum_sensor->publish_state(ene_total1 + ene_total2 + ene_total3);

//    ESP_LOGD("SDM", "End reading");
  }
};
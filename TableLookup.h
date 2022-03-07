#pragma once

#include <array>

namespace Lookup {



	enum PropertyNames
	{
		T, h, pr, u, vr, s, numProperties
	};

	struct PropertyValue
	{
		double temperature;
		double enthalpy;
		double relativePressure;
		double internalEnergy;
		double relativeVolume;
		double entropy;
	};


	class TableLookup
	{
	public:
		PropertyValue Lookup(PropertyNames Pn, double value);


	private:
		static std::array<double, 726>& airProperties;
		double getValueFromIndex(PropertyNames Pn, int index, double fraction);


	};

}
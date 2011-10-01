
#ifndef INNOEXTRACT_SETUPVERSIONDATA_HPP
#define INNOEXTRACT_SETUPVERSIONDATA_HPP

#include <iostream>
#include "Types.hpp"
#include "Version.hpp"

struct WindowsVersion {
	
	struct Version {
		
		unsigned major;
		unsigned minor;
		unsigned build;
	
		inline bool operator==(const Version & o) const {
			return (build == o.build && major == o.major && minor == o.minor);
		}
		
		inline bool operator!=(const Version & o) const {
			return !(*this == o);
		}
		
		void load(std::istream & is, const InnoVersion & version);
		
	};
	
	Version winVersion;
	Version ntVersion;
	
	struct ServicePack {
		
		unsigned major;
		unsigned minor;
	
		inline bool operator==(const ServicePack & o) const {
			return (major == o.major && minor == o.minor);
		}
		
		inline bool operator!=(const ServicePack & o) const {
			return !(*this == o);
		}
		
	};
	
	ServicePack ntServicePack;
	
	void load(std::istream & is, const InnoVersion & version);
	
	inline bool operator==(const WindowsVersion & o) const {
		return (winVersion == o.winVersion
		        && ntServicePack == o.ntServicePack
		        && ntServicePack == o.ntServicePack);
	}
	
	inline bool operator!=(const WindowsVersion & o) const {
		return !(*this == o);
	}
	
	const static WindowsVersion none;
	
};

std::ostream & operator<<(std::ostream & os, const WindowsVersion::Version & svd);
std::ostream & operator<<(std::ostream & os, const WindowsVersion & svd);

#endif // INNOEXTRACT_SETUPVERSIONDATA_HPP

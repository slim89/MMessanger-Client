
Name:pager
Version:0.1.0
Release:1
Summary:  <insert up to 60 chars description>
Source:%{name}-%{version}.tar.gz
License:lgpl
Prefix:/

%description
 <insert long description, indented with spaces>
%prep
%setup -q -n %{name}-%{version}

%build
qmake -r -spec linux-g++ CONFIG+=debug && make -w

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}
make install INSTALL_ROOT=%{buildroot}

%files
/


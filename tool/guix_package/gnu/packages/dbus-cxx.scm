;;; Copyright © 2020 Arthur Margerit <ruhtra.mar@gmail.com>
;;;
;;; This file is part of GNU Guix.
;;;
;;; GNU Guix is free software; you can redistribute it and/or modify it
;;; under the terms of the GNU General Public License as published by
;;; the Free Software Foundation; either version 3 of the License, or (at
;;; your option) any later version.
;;;
;;; GNU Guix is distributed in the hope that it will be useful, but
;;; WITHOUT ANY WARRANTY; without even the implied warranty of
;;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;; GNU General Public License for more details.
;;;
;;; You should have received a copy of the GNU General Public License
;;; along with GNU Guix.  If not, see <http://www.gnu.org/licenses/>.

(define-module (gnu packages dbus-cxx)
  #:use-module (guix packages)
  #:use-module (guix git-download)
  #:use-module (guix build-system cmake)
  #:use-module (guix licenses)
  #:use-module (gnu packages pkg-config)
  #:use-module (gnu packages m4)
  #:use-module ((gnu packages glib) #:select (dbus libsigc++)))

(define-public dbus-cxx
  (package
    (name "dbus-cxx")
    (version "0.12.0")
    (source (origin
              (file-name (git-file-name name version))
              (method git-fetch)
              (uri (git-reference
                    (url "https://github.com/dbus-cxx/dbus-cxx")
                    (commit "ea7f8e361d11dc7d41d9ae2c4128aed2cdadd84e")))
              (sha256
               (base32
                "1sa448icfvl08rnik0lnk4scmkwhfyd3mrxh36jh8x7xndp90khp"))))
    (build-system cmake-build-system)
    (arguments
     `(#:tests? #f))
    (inputs `(("dbus-glib", dbus) ("libsigc++", libsigc++)))
    (native-inputs `(("pkg-config", pkg-config) ("m4", m4)))
    (synopsis "C++ wrapper for dbus")
    (description "Dbus-cxx is a C++ wrapper for dbus.
It exposes the C API to allow direct manipulation and
relies on sigc++ to provide an OO interface.
Also included is dbus-cxx-xml2cpp to generate proxy and adapter
 interfaces from DBus XML introspection-like documents.")
    (home-page "https://dbus-cxx.github.io/")
    (license gpl3)))
